#!/bin/bash

echo -e "\n./philo 1 1"
./philo 1 1
echo -e "\n./philo 1 1 1 1 1 1 1"
./philo 1 1 1 1 1 1 1
echo -e "\n./philo 1 -80 200 200 7"
./philo 1 -80 200 200 7
echo -e "\n./philo 1 a 200 200 7"
./philo 1 a 200 200 7
echo -e "\n./philo 0 800 200 200 7"
./philo 0 800 200 200 7
echo -e "\n./philo 201 800 200 200 7"
./philo ./philo 201 800 200 200 7
echo -e "\n./philo 1 800 200 200 0"
./philo 1 800 200 200 0
echo -e "\n"
