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





void ReceiveSamples(int port_fd){
    memset(rx_buf, 0, BUFFER_SIZE);

    bool end_delimiter = false;
    
    int bytes_read = 0;
    for(;;){
        //read bytes from port;
        bytes_read += read(port_fd, rx_buf + bytes_read, BUFFER_SIZE - bytes_read);
        if(bytes_read < 0){
            perror("read");
        }

        if (bytes_read >= BUFFER_SIZE) {
            fprintf(stderr, "RX buffer overflow. No delimiter found\n");
            break;

        }else{
            end_delimiter = check_delimiter(bytes_read, BUFFER_SIZE - bytes_read);

        }
    }

    //check delimiter
    if(end_delimiter){
        //Plot all of rx from 0 to delimiter

        //Clear buffer
        memset(rx_buf, 0, BUFFER_SIZE);
    }
}




