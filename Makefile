mysql_lib=`mysql_config --cflags --libs`
modbusdir=-L/home/travis/build/Mattti0/Embedded-Systems-Programming/rpi-mb/libmodbus/src/.libs/ \
-I/home/travis/build/Mattti0/Embedded-Systems-Programming/rpi-mb/libmodbus/src `pkg-config --cflags --libs libmodbus`
#modbusdir=`pkg-config --cflags --libs libmodbus`
comfile=rpi-mb/modbus_update.c
flags=-Wall -ansi -pedantic

all:
	gcc $(flags) $(comfile) $(modbusdir) $(mysql_lib)
