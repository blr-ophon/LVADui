#ifndef UART_H
#define UART_H

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>


int UART_getfd(char *port, speed_t baud_rate);

#endif
