mysql_lib=-L/usr/lib/arm-linux-gnueabihf -lmysqlclient -lpthread -lz -lm -ldl

all:
	gcc ./rpi-mb/modbus_update.c $(mysql_lib) `pkg-config --libs --cflags libmodbus`

