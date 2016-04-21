mysql_lib = `mysql_config --cflags --libs`
modbusdep = -L./rpi-mb/libmodbus/src/.libs/ 
modbusdep += -I./rpi-mb/libmodbus/src 
modbusdep += `pkg-config --cflags --libs libmodbus`
modbussrc = rpi-mb/modbus_update.c
flags = -Wall -ansi -pedantic

all: modbus_reader

modbus_reader: $(modbussrc)
	gcc -o modbus_reader $(flags) $(modbussrc) $(modbusdep) $(mysql_lib)

