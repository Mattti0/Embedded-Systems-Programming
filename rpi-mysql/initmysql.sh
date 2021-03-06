#!/bin/bash

## Fill your own details ##
server="localhost"
user="root"
password="YOUR PASSWORD HERE"
base="iec_base"
addresstable="tIndex"
valuetable="tValues"



if [ $# -eq 0 ]
  then
    if [ $server = localhost ]
      then
	    	mysql -u $user -p$password -e "CREATE DATABASE IF NOT EXISTS ${base};"
				mysql -u $user -p$password -e "CREATE TABLE IF NOT EXISTS ${base}.${addresstable}(id INT NOT NULL, mb_addr INT NOT NULL, iec_name VARCHAR(50) NOT NULL, PRIMARY KEY(id));"
				mysql -u $user -p$password -e "CREATE TABLE IF NOT EXISTS ${base}.${valuetable}(id INT NOT NULL,Value FLOAT(7,2) NOT NULL,Time BIGINT NOT NULL,Validness INT NOT NULL,PRIMARY KEY(id));"
				mysql -u $user -p$password -e "INSERT INTO ${base}.${addresstable} VALUES (1, 2104, 'AnIn0'), (2, 2105, 'AnIn1'), (3, 2106, 'AnIn2'), (4, 2107, 'AnIn3'); "
				mysql -u $user -p$password -e "INSERT INTO ${base}.${valuetable} VALUES (1, 0.00, 0, 'False'), (2, 0.00, 0, 'False'), (3, 0.00, 0, 'False'), (4, 0.00, 0, 'False'); "
    elif [ $server -n ]
			then
				echo "mysql -h $server -u $user -p $password" > /dev/null
    fi
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
