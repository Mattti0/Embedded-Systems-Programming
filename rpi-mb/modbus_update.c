/*
 * modbus_update.c
 *
 *  Created on: 20.3.2016
 *      Author: Matti
 */
#include <mysql.h>
#include <modbus.h>

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

	char *my_server = "localhost";
	char *my_user = "iec_usr";
	char *my_pass = "iec_pass";
	char *database = "iec_base";

	char query[256];
	int column;
	int row = 0;

	my_con = mysql_init(NULL);

	mysql_real_connect(my_con, my_server, my_user, my_pass, database, 0, NULL, 0);

	modbus_t *mb_con;
	uint16_t tempMBValue;
	int ret;
//	float tempValue;



	while(1)
	{
		if(!mysql_query(my_con, "SELECT id, mb_addr FROM tIndex"))
		{
			result = mysql_store_result(my_con);

			while((row = mysql_fetch_row(result)))
			{
				if((modbus_read_input_registers(mb_con, row[1], &tempMBValue) = ret) > 0)
				{
					sprintf(query, "UPDATE tValues SET Value = %d, Time = %s, Validness = 'TRUE' WHERE id = %d;", tempMBValue, time_stamp, row[0]);
					if(!mysql_query(my_con, query))
					{
					}
				}
				else if (ret == 0)
				{
					sprintf(query, "UPDATE tValues SET Validness = 'FALSE' WHERE id = %d;", row[0]);
				}
			}
		}
		sleep(10);
	}

   mysql_free_result(result);
   mysql_close(my_con);
}

