mysql_lib=`mysql_config --cflags --libs`
modbusdir=-L/home/travis/build/Mattti0/Embedded-Systems-Programming/rpi-mb/libmodbus/src/.libs/ \
-I/home/travis/build/Mattti0/Embedded-Systems-Programming/rpi-mb/libmodbus/src `pkg-config --cflags --libs libmodbus`
#modbusdir=`pkg-config --cflags --libs libmodbus`
comfile=rpi-mb/modbus_update.c

all:
	gcc $(modbusdir) $(comfile) $(mysql_lib)
