mysql_lib=-L/usr/lib/arm-linux-gnueabihf -lmysqlclient -lpthread -lz -lm -ldl
modbusdir=`pkg-config --cflags --libs libmodbus`
comfile=./rpi-mb/modbus_update.c

all:
	gcc $(mysql_lib) $(modbusdir) $(comfile)
