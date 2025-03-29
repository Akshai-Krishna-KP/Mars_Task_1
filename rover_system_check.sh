#!/bin/bash

# generate a random Battery Percentage
 bperc=$((RANDOM % 101))
 echo "Battery Percentage : $bperc%\n"

# check if battery percentage is below 20% or not
 if $bperc -lt 20; then
	 echo "Battery low! Return to base!" | tee -a rover_log.log
	 exit 1
 fi

# check network connectivity 
 if ! ping -c 2 google.com > /dev/null 2>&1; then
	 echo "Communication failure!" | tee -a rover_log.log
	 exit 1
 fi

# if both are okay
 echo "All system operational!" | tee -a rover_log.log
 exit 0
