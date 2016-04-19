/*
 *  server_example3.c
 *
 *  - How to use simple control models
 *  - How to serve analog measurement data
 */

#include "iec61850_server.h"
#include "hal_thread.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <mysql.h>
#include <string.h>

#include "static_model.h"
#include "../../rpi-mysql/mysql_info.h"

typedef struct {
	float value;
	Timestamp ts;
	char validity;
} iecValue_t;

static iecValue_t values[4];


static void * objects[4] = {IEDMODEL_VaconFreqConverter_DSFC1_AnIn0,
					IEDMODEL_VaconFreqConverter_DSFC1_AnIn1,
					IEDMODEL_VaconFreqConverter_DSFC1_AnIn2,
					IEDMODEL_VaconFreqConverter_DSFC1_AnIn3};

static const char *names[4] = {"AnIn0", "AnIn1", "AnIn2", "AnIn3"};

/* import IEC 61850 device model created from SCL-File */
extern IedModel iedModel;

static int running = 0;
static IedServer iedServer = NULL;

MYSQL *my_con;
MYSQL_RES *result;
MYSQL_ROW row;

void
sigint_handler(int signalId)
{
    running = 0;
}

void getValuesFromDatabase()
{
	int i;
	char query[256];
	int column;
	int ret;
	MYSQL_ROW row_temp;
	MYSQL_RES *res_temp;

	sprintf(query, "SELECT id FROM %s WHERE iec_name = '%s'", idTable, names[i]);
	if (!mysql_query(my_con, query))
	{
		result = mysql_store_result(my_con);
		for (i = 0; i < 4; i++)
		{
			row_temp = mysql_fetch_row(result);
			sprintf(query, "SELECT Value, Time, Validness FROM %s WHERE id = %d", valueTable, row_temp[0]);
			if (!mysql_query(my_con, query))
			{
				res_temp = mysql_store_result(my_con);
				row = mysql_fetch_row(res_temp);
				values[i].value = atof(row[0]);
				Timestamp_setTimeInSeconds(&values[i].ts, atol(row[1]));
				if(!strcmp(row[2], "True"))
					values[i].validity = 1;
				else
					values[i].validity = 0;
			}

		}
	}

}


void getTimestamps(Timestamp *ts)
{
	int i;
    uint64_t timestamp = Hal_getTimeInMs();

    for(i = 0; i < 10; i++)
    {
        Timestamp_clearFlags(ts+i);
        Timestamp_setTimeInMilliseconds(ts+i, timestamp);
        Timestamp_setLeapSecondKnown(ts+i, true);
    }

}

void updateValues()
{
	int i;
    IedServer_lockDataModel(iedServer);
    for (i = 0; i < 4; i++)
    {
    	IedServer_updateTimestampAttributeValue(iedServer, objects[i], &values[i].ts);
        IedServer_updateFloatAttributeValue(iedServer, objects[i], values[i].value);
    }
    IedServer_unlockDataModel(iedServer);
}

static ControlHandlerResult
controlHandlerForBinaryOutput(void* parameter, MmsValue* value, bool test)
{
	int i;
    if (test)
        return CONTROL_RESULT_FAILED;

    if (MmsValue_getType(value) == MMS_BOOLEAN) {
        printf("received binary control command: ");

        if (MmsValue_getBoolean(value))
            printf("on\n");
        else
            printf("off\n");
    }
    else
        return CONTROL_RESULT_FAILED;

    uint64_t timeStamp = Hal_getTimeInMs();

    for (i = 0; i < 4; i++)
    {
    	if (parameter == objects[i])
    	{
    		IedServer_updateUTCTimeAttributeValue(iedServer, objects[i], timeStamp);
    		IedServer_updateAttributeValue(iedServer, objects[i], value);
    	}
    }

    return CONTROL_RESULT_OK;
}


static void
connectionHandler (IedServer self, ClientConnection connection, bool connected, void* parameter)
{
    if (connected)
        printf("Connection opened\n");
    else
        printf("Connection closed\n");
}

int
main(int argc, char** argv)
{
    printf("Using libIEC61850 version %s\n", LibIEC61850_getVersionString());

    iedServer = IedServer_create(&iedModel);

    /* Install handler for operate command */
    IedServer_setControlHandler(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn0,
            (ControlHandler) controlHandlerForBinaryOutput,
			IEDMODEL_VaconFreqConverter_DSFC1_AnIn0);

    IedServer_setControlHandler(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn1,
            (ControlHandler) controlHandlerForBinaryOutput,
			IEDMODEL_VaconFreqConverter_DSFC1_AnIn1);

    IedServer_setControlHandler(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn2,
            (ControlHandler) controlHandlerForBinaryOutput,
			IEDMODEL_VaconFreqConverter_DSFC1_AnIn2);

    IedServer_setControlHandler(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn3,
            (ControlHandler) controlHandlerForBinaryOutput,
			IEDMODEL_VaconFreqConverter_DSFC1_AnIn3);

    IedServer_setConnectionIndicationHandler(iedServer, (IedConnectionIndicationHandler) connectionHandler, NULL);

    /* MMS server will be instructed to start listening to client connections. */
    IedServer_start(iedServer, 102);

    if (!IedServer_isRunning(iedServer)) {
        printf("Starting server failed! Exit.\n");
        IedServer_destroy(iedServer);
        exit(-1);
    }

	my_con = mysql_init(NULL);
	mysql_real_connect(my_con, server, my_user, my_pass, database, 0, NULL, 0);

	running = 1;

    signal(SIGINT, sigint_handler);

    while (running) {

    	getValuesFromDatabase();

    	updateValues();

        Thread_sleep(100);
    }

    /* stop MMS server - close TCP server socket and all client sockets */
    IedServer_stop(iedServer);

    /* Cleanup - free all resources */
    IedServer_destroy(iedServer);

} /* main() */
