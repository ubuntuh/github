set term png
set output "output.png"
plot "test.dat" u 1:2 with line linecolor "blue"
