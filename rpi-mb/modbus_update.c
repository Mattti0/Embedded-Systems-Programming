/*
 * modbus_update.c
 *
 *  Created on: 20.3.2016
 *      Author: Matti
 */
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <mysql/mysql.h>
#include <modbus.h>
#include "../rpi-mysql/mysql_info.h"

#ifndef __MYSQL_INFO_H_
#error "MySQL info not exists run rpi-mysql/initmysql.sh"
#endif

char *time_stamp(){

	char *timestamp = (char *)malloc(sizeof(char) * 20);
	time_t ltime;
	ltime=time(NULL);
	struct tm *tm;
	tm=localtime(&ltime);

	sprintf(timestamp,"%04d-%02d-%02d %02d:%02d:%02d", tm->tm_year+1900, tm->tm_mon,
		tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
	return timestamp;
}

int main(void)
{
	MYSQL *my_con;
	MYSQL_RES *result;
	MYSQL_ROW row;

/*	char *my_server = "localhost";
	char *my_user = "iec_usr";
	char *my_pass = "iec_pass";
	char *database = "iec_base";*/
	my_con = mysql_init(NULL);
	mysql_real_connect(my_con, server, my_user, my_pass, database, 0, NULL, 0);

	char query[256];
	int column;

	modbus_t *mb_con;
	uint16_t tempMBValue;
	uint16_t tempMBAddress;
	int ret;

	mb_con = modbus_new_rtu("/dev/ttyUSB0", 9600, 'N', 8, 2);
	modbus_rtu_set_serial_mode(mb_con, MODBUS_RTU_RS485);

	while(1)
	{
		sprintf(query, "SELECT id, mb_addr FROM %s", idTable);
		/*if(!mysql_query(my_con, "SELECT id, mb_addr FROM tIndex"))*/
		if(!mysql_query(my_con, query))
		{
			result = mysql_store_result(my_con);

			while((row = mysql_fetch_row(result)))
			{
				if((ret = modbus_read_input_registers(mb_con, atoi(row[1]), 1, &tempMBValue)) > 0)
				{
					sprintf(query, "UPDATE %s SET Value = %d, Time = %s, Validness = 'TRUE' WHERE id = %d;", valueTable, tempMBValue, time_stamp, atoi(row[0]));
					if(!mysql_query(my_con, query))
					{
					}
				}
				else if (ret == 0)
				{
					sprintf(query, "UPDATE %s SET Validness = 'FALSE' WHERE id = %d;", valueTable, atoi(row[0]));
				}
			}
		}
		sleep(1);
	}

	modbus_free(mb_con);
	mysql_free_result(result);
	mysql_close(my_con);
}

