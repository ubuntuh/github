# http://note.kurodigi.com/gnuplot-usage-basic/#id308
set term png font "IPAPGothic"
set output "output.png"
set yrange [0:500]
set xrange [0:80]
set xlabel "時間"
set ylabel "温度"
set xtics 10
set mxtics 2
set ytics 100
plot "test.dat" u 1:2 with line linecolor "blue" title "テスト 1"
