#!/bin/bash

server="localhost"
user="root"
password="root"
base="iec_base"
addresstable="tIndex"
valuetable="tValues"


if [-z $1]
then
	if [ $server = localhost ]
	then
		mysql -u $user -p $password << EOF
	elif [ $server -n ]
		mysql -h $server -u $user -p $password << EOF
	fi
	

	CREATE DATABASE IF NOT EXISTS ${base};
	USE ${base};
	
	CREATE TABLE IF NOT EXISTS ${addresstable}(
		id INT NOT NULL,
		mb_addr NOT NULL UNSIGNED MEDIUMINT,
		iec_name VARCHAR(50) NOT NULL,
		PRIMARY_KEY(id));
		
	CREATE TABLE IF NOT EXISTS ${vauetable}(
		id INT NOT NULL,
		Value FLOAT(7,2) NOT NULL,
		Time DATETIME NOT NULL,
		Validness BOOL NOT NULL,
		PRIMARY_KEY(id));
	
fi
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

