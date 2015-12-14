set term png
set output "output.png"
set datafile separator ","
set title "Japanese population by sex (2015)"
set xlabel "Age"
set ylabel "Population"
# http://gnuplot.10905.n7.nabble.com/quot-set-decimalsign-quot-for-thousand-separator-td8369.html
set decimal locale "en_US.UTF-8"
set format y "%'.0f"
set xrange [0 : 100]
plot \
    "danjobetsu-jinkou-2015-june.csv" using 1:2 with boxes title "Total",\
    "danjobetsu-jinkou-2015-june.csv" using 1:3 with linespoint title "Male",\
    "danjobetsu-jinkou-2015-june.csv" using 1:4 with linespoint title "Female",\
