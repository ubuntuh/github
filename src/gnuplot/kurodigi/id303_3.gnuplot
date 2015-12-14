set term png
set output "output.png"
plot x ** 3 with line, x ** 3 + 100 with point, x ** 3 + 200 with linespoint, x ** 3 + 300 with dot, x ** 3 + 400 with boxes, x ** 3 + 500 with vector
