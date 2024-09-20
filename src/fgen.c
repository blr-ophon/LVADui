#include "fgen.h"



// Y(t) = Asin(wt)
static double FGen_SINE(Wave wave, double time){
    return wave.amp * sin(2*M_PI * wave.freq * time);
}

static double FGen_SQUARE(Wave wave, double time){
    return (sin(2*M_PI * wave.freq * time) >= 0) ? wave.amp : -wave.amp;
}

double (*FGen_WAVEFORM[])(Wave, double) = {
    FGen_SINE,
    FGen_SQUARE,
    NULL
};



void FGen_out(FILE *f, Wave wave, double sample_rate, int duration){
    double period = 1/sample_rate;
    int samples_total = duration/period;



    for(int i = 0; i < samples_total; i++){
        double time = i*period;     
        fprintf(f, "%f %f\n", time, FGen_WAVEFORM[wave.form](wave, time));
    }


    switch(wave.form){
        case WAV_SINE:
            break;
        case WAV_SQUARE:
            break;
        case WAV_TRIG:
            break;
        default:
            break;
    }
}
