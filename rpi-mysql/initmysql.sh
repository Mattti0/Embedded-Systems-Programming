#!/bin/bash

server="localhost"
user="root"
password="root"
base="iec_base"
addresstable="tIndex"
valuetable="tValues"


#if [ -z $1 ]
#	then
#		if [ $server = localhost ]
#			then
#				echo "mysql -u $user -p $password" > /dev/null
#			elif [ $server -n ]
#				echo "mysql -h $server -u $user -p $password" > /dev/null
#		fi
#		echo	"CREATE DATABASE IF NOT EXISTS ${base};"
#		echo	"USE ${base};"
#
#		echo	"CREATE TABLE IF NOT EXISTS ${addresstable}("
#		echo		"id INT NOT NULL,"
#		echo		"mb_addr NOT NULL UNSIGNED MEDIUMINT,"
#		echo		"iec_name VARCHAR(50) NOT NULL,"
#		echo		"PRIMARY_KEY(id));"
#
#		echo	"CREATE TABLE IF NOT EXISTS ${valuetable}("
#		echo		"id INT NOT NULL,"
#		echo		"Value FLOAT(7,2) NOT NULL,"
#		echo		"Time DATETIME NOT NULL,"
#		echo		"Validness BOOL NOT NULL,"
#		echo		"PRIMARY_KEY(id));"
#fi
## Create mysql header file ##

echo "#ifndef __MYSQL_INFO_H_" > mysql_info.h
echo "#define __MYSQL_INFO_H_" >> mysql_info.h
echo "char *server = \""${server}"\";" >> mysql_info.h
echo "char *my_user = \""${user}"\";" >> mysql_info.h
echo "char *my_pass = \""${password}"\";" >> mysql_info.h
echo "char *database = \""${base}"\";" >> mysql_info.h
echo "char *idTable = \""${addresstable}"\";" >> mysql_info.h
echo "char *valueTable = \""${valuetable}"\";" >> mysql_info.h
echo "#endif" >> mysql_info.h
