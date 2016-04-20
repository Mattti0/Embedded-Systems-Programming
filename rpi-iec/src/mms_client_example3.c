
#include <stdlib.h>
#include <stdio.h>
#include "mms_client_connection.h"

int main(int argc, char** argv) {

	char* hostname;
	int tcpPort = 102;

	if (argc > 1)
		hostname = argv[1];
	else
		hostname = "localhost";

	if (argc > 2)
		tcpPort = atoi(argv[2]);

	MmsConnection con = MmsConnection_create();

	MmsError error;

	if (!MmsConnection_connect(con, &error, hostname, tcpPort)) {
		printf("MMS connect failed!\n");
		goto exit;
	}
	else
		printf("MMS connected.\n\n");
/*
	LinkedList nameList = MmsConnection_getDomainNames(con, &error);
	LinkedList element = nameList;

	while ((element = LinkedList_getNext(element)) != NULL) {
  	  char* str = (char*) (element->data);
  	  printf("%s\n", str);
	}

	nameList = MmsConnection_getDomainVariableNames(con, &error,  "SampleIEDVaconFreqConverter");
	element = nameList;
	while ((element = LinkedList_getNext(element)) != NULL) {
  	  char* str = (char*) (element->data);
  	  printf("%s\n", str);
	}

	nameList = MmsConnection_getDomainVariableListNames(con, &error, "SampleIEDVaconFreqConverter");
	element = nameList;

	while ((element = LinkedList_getNext(element)) != NULL) {
   		char* str = (char*) (element->data);
  	  printf("%s\n", str);
	}

*/

	MmsValue* value =
			MmsConnection_readVariable(con, &error, "SampleIEDVaconFreqConverter", "DSFC1$MX$AnIn0$mag$f");



	if (value == NULL)
		printf("reading value failed!\n");
	else
	{
//		printf("type: %d\n", (int)MmsValue_getType(value));
		float f = MmsValue_toFloat(value);
		MmsValue_delete(value);
		printf("Value: %f\n", f);
	}
exit:
	MmsConnection_destroy(con);
}

