mysql_lib=-L/usr/lib/arm-linux-gnueabihf -lmysqlclient -lpthread -lz -lm -ldl
modbusdir=`pkg-config --cflags --libs libmodbus`


all:
	gcc ./rpi-mb/modbus_update.c $(mysql_lib) $(modbusdir)
