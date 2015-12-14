set term png
set output "output.png"
set xlabel "Time [min]"
set ylabel "Time [min]"
set xrange [20 : 80]
set xtics 20
set mxtics 5
plot "test.dat"
