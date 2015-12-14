set term png
set output "output.png"
set datafile separator ","
set title "Japanese population by sex"
set xlabel "Year"
set ylabel "Population"
set decimal locale "en_US.UTF-8"
set format y "%'.0f"
set xrange [1920 : 2000]
set yrange [0 : 130000000]
plot \
    "danjobetsu-jinkou-1920-to-2000.csv" using 1:2 with boxes title "Total",\
    "danjobetsu-jinkou-1920-to-2000.csv" using 1:3 with linespoint title "Male",\
    "danjobetsu-jinkou-1920-to-2000.csv" using 1:4 with linespoint title "Female",\
