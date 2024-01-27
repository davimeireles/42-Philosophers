cmake_minimum_required(VERSION 3.24)
project(philo C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(philo
        date_utils.c
        main.c
        philo.h
        philo_utils.c
        routine.c
        thread_utils.c
        utils.c
        validate_input.c)
