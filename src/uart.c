#include "uart.h"

/*
 * Given the name of a serial port and a Baud Rate
 * returns a file descriptor
 */
int UART_getfd(char *port, speed_t baud_rate){
    int fd;
    struct termios options;

    fd = open(port, O_RDONLY | O_NONBLOCK | O_NOCTTY);

    if(fd < 0){
        printf("Error opening serial port\n");
        perror("open");
        fd = -1;
        goto out;
    }else{
        printf("Serial Port: %s\n", port);
        printf("Baud Rate: %d\n", baud_rate);
    }

    
    /* 
     * SERIAL PORT SETUP
     *
     * CS8: 8-bit characters
     * CLOCAL: Local Connection. Ignore modem control signals
     * IGNPAR: Ignore parity errors
     */
    options.c_cflag = baud_rate | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;

    //Apply settings
    tcflush(fd, TCIFLUSH);
    tcsetattr(fd, TCSANOW, &options);

out:
    return fd;
}


