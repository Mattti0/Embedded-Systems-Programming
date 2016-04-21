mysql_lib=`mysql_config --cflags --libs`
modbusdir=-L./rpi-mb/libmodbus/src/.libs/ \
-I./rpi-mb/libmodbus/src `pkg-config --cflags --libs libmodbus`
modbusfiles=rpi-mb/modbus_update.c
flags=-Wall -ansi -pedantic

all: modbus_reader

modbus_reader: $(modbusfiles)
	gcc -o modbus_reader $(flags) $(modbusfiles) $(modbusdir) $(mysql_lib)

