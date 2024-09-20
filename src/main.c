#include <stdlib.h>
#include "fgen.h"
#include "config.h"
#include "uart.h"

int main(void){

    //5v 1khz sine wave
    Wave wav1 = {
        WAV_SINE,       
        300,
        5
    };
    Wave wav2 = {
        WAV_SQUARE,       
        300,
        5
    };
    Wave wav3 = {
        WAV_TRIG,       
        300,
        5
    };

    FILE *plot1 = fopen("./fgen_sine.dat", "w");
    FILE *plot2 = fopen("./fgen_square.dat", "w");
    FILE *plot3 = fopen("./fgen_trig.dat", "w");

    FGen_out(plot1, wav1, SAMPLE_RATE, DURATION);
    FGen_out(plot2, wav2, SAMPLE_RATE, DURATION);
    FGen_out(plot3, wav3, SAMPLE_RATE, DURATION);

    system("gnuplot fgen.gnuplot");
}
