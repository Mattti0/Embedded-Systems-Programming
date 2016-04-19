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

#include "static_model.h"
#include "../../rpi-mysql/mysql_info.h"

/* import IEC 61850 device model created from SCL-File */
extern IedModel iedModel;

static int running = 0;
static IedServer iedServer = NULL;

void
sigint_handler(int signalId)
{
    running = 0;
}

void getValuesFromDatabase(float *val)
{
	int i;
	for(i = 0; i < 10; i++)
	{

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

void updateValues(float *val, Timestamp *ts)
{
    IedServer_lockDataModel(iedServer);
    IedServer_updateTimestampAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn0_t, ts);
    IedServer_updateFloatAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn0_mag_f, *(val));
    IedServer_updateTimestampAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn1_t, ts+1);
    IedServer_updateFloatAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn1_mag_f, *(val+1));
    IedServer_updateTimestampAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn2_t, ts+2);
    IedServer_updateFloatAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn2_mag_f, *(val+2));
    IedServer_updateTimestampAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn3_t, ts+3);
    IedServer_updateFloatAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn3_mag_f, *(val+3));
    IedServer_updateTimestampAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn4_t, ts+4);
    IedServer_updateFloatAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn4_mag_f, *(val+4));
    IedServer_updateTimestampAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn5_t, ts+5);
    IedServer_updateFloatAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn5_mag_f, *(val+5));
    IedServer_updateTimestampAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn6_t, ts+6);
    IedServer_updateFloatAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn6_mag_f, *(val+6));
    IedServer_updateTimestampAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn7_t, ts+7);
    IedServer_updateFloatAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn7_mag_f, *(val+7));
    IedServer_updateTimestampAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn8_t, ts+8);
    IedServer_updateFloatAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn8_mag_f, *(val+8));
    IedServer_updateTimestampAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn9_t, ts+9);
    IedServer_updateFloatAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn9_mag_f, *(val+9));
    IedServer_unlockDataModel(iedServer);
}

static ControlHandlerResult
controlHandlerForBinaryOutput(void* parameter, MmsValue* value, bool test)
{
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

    if (parameter == IEDMODEL_VaconFreqConverter_DSFC1_AnIn0) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn0_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn0_mag_f, value);
    }

    if (parameter == IEDMODEL_VaconFreqConverter_DSFC1_AnIn1) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn1_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn1_mag_f, value);
    }

    if (parameter == IEDMODEL_VaconFreqConverter_DSFC1_AnIn2) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn2_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn2_mag_f, value);
    }

    if (parameter == IEDMODEL_VaconFreqConverter_DSFC1_AnIn3) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn3_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_VaconFreqConverter_DSFC1_AnIn3_mag_f, value);
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
	MYSQL *my_con;
	MYSQL_RES *result;
	MYSQL_ROW row;

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

    running = 1;

    signal(SIGINT, sigint_handler);

    float val[10];
    Timestamp t[10];

    while (running) {

    	getValuesFromDatabase(&val);
    	getTimestamps(&t);

        updateValues(&val, &t);


        Thread_sleep(100);
    }

    /* stop MMS server - close TCP server socket and all client sockets */
    IedServer_stop(iedServer);

    /* Cleanup - free all resources */
    IedServer_destroy(iedServer);

} /* main() */
