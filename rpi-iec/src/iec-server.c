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

/* import IEC 61850 device model created from SCL-File */
extern IedModel iedModel;

static int running = 0;
static IedServer iedServer = NULL;

void
sigint_handler(int signalId)
{
    running = 0;
}

void getValues(float *val)
{

}

void getTimestamps(Timestamp *ts)
{
    uint64_t timestamp = Hal_getTimeInMs();

    for(int i = 0; i < 10; i++)
    {
        Timestamp_clearFlags(ts+i);
        Timestamp_setTimeInMilliseconds(ts+i, timestamp);
        Timestamp_setLeapSecondKnown(ts+i, true);

        /* toggle clock-not-synchronized flag in timestamp */
        if (((int) t % 2) == 0)
            Timestamp_setClockNotSynchronized(ts+i, true);

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

    if (parameter == IEDMODEL_GenericIO_GGIO1_SPCSO1) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GenericIO_GGIO1_SPCSO1_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_GenericIO_GGIO1_SPCSO1_stVal, value);
    }

    if (parameter == IEDMODEL_GenericIO_GGIO1_SPCSO2) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GenericIO_GGIO1_SPCSO2_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_GenericIO_GGIO1_SPCSO2_stVal, value);
    }

    if (parameter == IEDMODEL_GenericIO_GGIO1_SPCSO3) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GenericIO_GGIO1_SPCSO3_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_GenericIO_GGIO1_SPCSO3_stVal, value);
    }

    if (parameter == IEDMODEL_GenericIO_GGIO1_SPCSO4) {
        IedServer_updateUTCTimeAttributeValue(iedServer, IEDMODEL_GenericIO_GGIO1_SPCSO4_t, timeStamp);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_GenericIO_GGIO1_SPCSO4_stVal, value);
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
   MYSQL *conn;
   MYSQL_RES *res;
   MYSQL_ROW row;
   char *server = "localhost";
   char *user = "root";
   char *password = "PASSWORD"; /* set me first */
   char *database = "mysql";
    printf("Using libIEC61850 version %s\n", LibIEC61850_getVersionString());

    iedServer = IedServer_create(&iedModel);

    /* Install handler for operate command */
    IedServer_setControlHandler(iedServer, IEDMODEL_GenericIO_GGIO1_SPCSO1,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_GenericIO_GGIO1_SPCSO1);

    IedServer_setControlHandler(iedServer, IEDMODEL_GenericIO_GGIO1_SPCSO2,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_GenericIO_GGIO1_SPCSO2);

    IedServer_setControlHandler(iedServer, IEDMODEL_GenericIO_GGIO1_SPCSO3,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_GenericIO_GGIO1_SPCSO3);

    IedServer_setControlHandler(iedServer, IEDMODEL_GenericIO_GGIO1_SPCSO4,
            (ControlHandler) controlHandlerForBinaryOutput,
            IEDMODEL_GenericIO_GGIO1_SPCSO4);

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

    float val;
    Timestamp t;

    while (running) {

    	getValues(&val);
    	getTimestamps(&t);

        updateValues(&val, &t);


        Thread_sleep(100);
    }

    /* stop MMS server - close TCP server socket and all client sockets */
    IedServer_stop(iedServer);

    /* Cleanup - free all resources */
    IedServer_destroy(iedServer);

} /* main() */
