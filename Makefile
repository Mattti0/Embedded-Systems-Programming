mysql_lib=-L/usr/lib/arm-linux-gnueabihf -lmysqlclient -lpthread -lz -lm -ldl
modbusdir=-I/home/travis/build/Mattti0/Embedded-Systems-Programming/rpi-mb/libmodbus/src `pkg-config --cflags --libs libmodbus`
#modbusdir=`pkg-config --cflags --libs libmodbus`
comfile=./rpi-mb/modbus_update.c

all:
	gcc $(mysql_lib) $(modbusdir) $(comfile)
