#!/bin/bash	

I=0
echo -n "input number:"
read S

while [ $I -lt $S ] 
do
	I=`expr $I + 1`
	echo "$I"
	>FILE$I
done
