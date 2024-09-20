#include <stdlib.h>
#include "fgen.h"
#include "config.h"
#include "uart.h"

int main(void){

    //5v 1khz sine wave
    Wave wav = {
        WAV_SINE,       
        1000,
        5
    };

    FILE *f = fopen("./sine.dat", "w");
    FGen_out(f, wav, SAMPLE_RATE, DURATION);
    system("gnuplot fgen.gnuplot");
}
