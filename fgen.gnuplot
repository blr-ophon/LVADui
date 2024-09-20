set xrange [0:0.005]
set yrange [-10:10]

while(1) {
    plot "sine.dat" using 1:2 with lines title 'fgen'
}
