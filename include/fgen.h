#ifndef FGEN_H
#define FGEN_H

#include <math.h>
#include <stdint.h>
#include <stdio.h>

typedef enum{
    WAV_SINE,
    WAV_SQUARE,
    WAV_TRIG
}WAV_FORM_t;

typedef struct{
    WAV_FORM_t form;
    int freq;
    int amp;
}Wave;


void FGen_out(FILE *f, Wave wave, double sample_rate, int duration);

#endif
