#!/bin/bash
writefile=$1
writestr=$2

if [ "$#" -lt 2 ]
then
	echo "Insufficient arguments"
	exit 1
else
	mkdir -p "$(dirname "$writefile")"
	touch "$writefile"
	echo "$writestr" > "$writefile"
fi

if [ ! -f "$writefile" ]
then
	echo "File not created"
	exit 1
else
	exit 0
fi
