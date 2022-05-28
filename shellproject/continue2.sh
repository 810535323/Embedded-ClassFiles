#!/bin/bash

I=1
while [ $I -lt 5 ]
do
	J=1
	while [ $J -lt 5 ]
	do
		J=`expr $J + 1`
		if [ $J -gt 3 ]
		then
			break 
		fi
		echo "$I-$J"
	done
	I=`expr $I + 1`
done

