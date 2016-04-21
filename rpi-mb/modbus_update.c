/*
 * modbus_update.c
 *
 *  Created on: 20.3.2016
 *      Author: Matti
 */
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <mysql/mysql.h>
#include <modbus.h>
#include <errno.h>
#include "../rpi-mysql/mysql_info.h"

#ifndef __MYSQL_INFO_H_
#error "MySQL info not exists run rpi-mysql/initmysql.sh"
#endif

int main(void)
{
	MYSQL *my_con;
	MYSQL_RES *result;
	MYSQL_ROW row;

	char query[256];

	modbus_t *mb_con;
	uint16_t tempMBValue;
	int ret;
	unsigned int timestamp;
	my_con = mysql_init(NULL);
	if(mysql_real_connect(my_con, server, my_user, my_pass, database, 0, NULL, 0))
		printf("Mysql connection succeed\n");
	else printf("Mysql nope...\n");

	my_con = mysql_init(NULL);
	mysql_real_connect(my_con, server, my_user, my_pass, database, 0, NULL, 0);

	mb_con = modbus_new_rtu("/dev/ttyUSB0", 9600, 'N', 8, 2);
	printf("mb_con: %d\n", mb_con);
	if (!modbus_rtu_set_serial_mode(mb_con, MODBUS_RTU_RS485))
		printf("Serial setted\n");
	else
		fprintf(stderr, "Set serial failed:%d\n ", errno);
	if (!modbus_set_slave(mb_con, 1))
		printf("Slave setted\n");
	modbus_connect(mb_con);

	while(1)
	{
		sprintf(query, "SELECT id, mb_addr FROM %s;", idTable);
		if(!mysql_query(my_con, query))
		{
			result = mysql_store_result(my_con);

			while((row = mysql_fetch_row(result)))
			{
				if((ret = modbus_read_input_registers(mb_con, atoi(row[1]), 1, &tempMBValue)) > 0)
				{
					timestamp = (unsigned int)time(NULL);
					sprintf(query, "UPDATE %s SET Value = %d, Time = %d, Validness = 'true' WHERE id = %d;", valueTable, (int)tempMBValue, timestamp, atoi(row[0]));
					if(!mysql_query(my_con, query))
					{
					}
				}
				else
				{
					sprintf(query, "UPDATE %s SET Validness = 'FALSE' WHERE id = %d;", valueTable, atoi(row[0]));
					if (!mysql_query(my_con, query))
					{
					}
				}
			}
		}
		else
			printf("mysql not connected\n");
		sleep(1);
	}
	modbus_close(mb_con);
	modbus_free(mb_con);
	mysql_free_result(result);
	mysql_close(my_con);
}

