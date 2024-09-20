#include "receiver.h"

#define BUFFER_SIZE     32000
#define DELIMITER_LEN   7
#define DELIMITER_VAL   0x77

uint8_t rx_buf[BUFFER_SIZE];




static bool check_delimiter(int buf_pos, int buf_size){
    if(buf_size < DELIMITER_LEN){
        return false;
    }

    int counter = 0;
    for(int i = 0; i < DELIMITER_LEN; i++){
        if(rx_buf[buf_pos - i] == DELIMITER_VAL){
            counter++;
        }else{
            break;
        }
    }

    return counter == DELIMITER_LEN;
}





int ReceiveSamples(int port_fd){
    int rv = 0;

    memset(rx_buf, 0, BUFFER_SIZE);

    int bytes_read = 0;

    memset(rx_buf, 0, BUFFER_SIZE);

    for(;;){
        //read bytes from port;
        bytes_read += read(port_fd, rx_buf + bytes_read, BUFFER_SIZE - bytes_read);
        if(bytes_read < 0){
            perror("read");
        }

        if (bytes_read >= BUFFER_SIZE) {
            fprintf(stderr, "RX buffer overflow. No delimiter found\n");
            break;

        }

        rv = check_delimiter(bytes_read, BUFFER_SIZE - bytes_read);
    }

    return rv;
}


void ConvertSamples(void){

}



