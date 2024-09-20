set xrange [0:20]
set yrange [-400:400]
set multiplot layout 2, 1


while(1) {
    set multiplot layout 2, 1
    plot "test1.dat" using 1:2 with lines title 'Teste 1(pow)'
    plot "test2.dat" using 1:2 with lines title 'Teste 2(sin)'
    pause 1

    unset multiplot
}


#    plot "test2.dat" using 1:2 with lines title 'Graph 1', \
#         "test1.dat" using 1:2 with lines title 'Graph 2'
