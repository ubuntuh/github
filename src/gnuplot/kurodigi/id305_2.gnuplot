set term png
set output "output.png"
plot "test.dat" u 1:2 with linespoint linecolor "#4682b4" linetype 5 linewidth 2
