mysql_lib = `mysql_config --cflags --libs`

LIBIEC_HOME=../libiec61850

PROJECT_BINARY_NAME = iec_server
PROJECT_SOURCES = iec-server.c
PROJECT_SOURCES += static_model.c

CLIENT_BINARY_NAME = mms_client_example3
CLIENT_SOURCES = mms_client_example3.c

PROJECT_ICD_FILE = model.icd

include $(LIBIEC_HOME)/make/target_system.mk
include $(LIBIEC_HOME)/make/stack_includes.mk

all:	$(PROJECT_BINARY_NAME) $(CLIENT_BINARY_NAME)

include $(LIBIEC_HOME)/make/common_targets.mk

LDLIBS += -lm
LDLIBS += $(mysql_lib)
CP = cp

model:	$(PROJECT_ICD_FILE)
	java -jar $(LIBIEC_HOME)/tools/model_generator/genmodel.jar $(PROJECT_ICD_FILE)

$(PROJECT_BINARY_NAME):	$(PROJECT_SOURCES) $(LIB_NAME)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(PROJECT_BINARY_NAME) $(PROJECT_SOURCES) $(INCLUDES) $(LIB_NAME) $(LDLIBS)

$(CLIENT_BINARY_NAME):	$(CLIENT_SOURCES) $(LIB_NAME)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(CLIENT_BINARY_NAME) $(CLIENT_SOURCES) $(INCLUDES) $(LIB_NAME) $(LDLIBS)

clean:
	rm -f $(PROJECT_BINARY_NAME)
	rm -f $(CLIENT_BINARY_NAME)


