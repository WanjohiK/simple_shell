#! /bin/bash

#This script prints the maximum possible process ID (PID).

#Define the path to the pid_max file.

pid_max_file="/proc/sys/kernel/pid_max"

#Check if the file exists and is accesible.

if [ -e "$pid_max_file" ]; then

	#Read the maximum PID value from the file.
	max_pid=$(cat "$pid_max_file")

	#Print the max PID value.
	echo "Maximum PID value: $max_pid"
else
	#Print an error message if the file is not accessible.
	echo "Error: $pid_max_file does not exist or is inaccessible."
fi

