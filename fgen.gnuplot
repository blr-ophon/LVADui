set xrange [0:0.05]
set yrange [-10:10]

set multiplot layout 3, 1

while(1) {
    plot "fgen_sine.dat" using 1:2 with lines title 'SINE'
    plot "fgen_square.dat" using 1:2 with lines title 'SQUARE'
    plot "fgen_trig.dat" using 1:2 with lines title 'TRIG'
}
