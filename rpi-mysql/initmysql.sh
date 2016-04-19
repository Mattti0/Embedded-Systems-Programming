#!/bin/bash

server="localhost"
user="root"
password="root"
base="iec_base"
table="iec_table"



if [ $server = localhost ]
then
	mysql -u $user -p $password << EOF
elif [ $server -n ]
	mysql -h $server -u $user -p $password << EOF
fi

CREATE DATABASE IF NOT EXISTS ${base};

