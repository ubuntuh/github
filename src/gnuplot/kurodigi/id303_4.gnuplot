set term png
set output "output.png"
splot x ** 2 + y ** 2 with line, x ** 2 + y ** 2 + 100 with point, x ** 2 + y ** 2 + 200 with linespoint, x ** 2 + y ** 2 + 300 with dot, x ** 2 + y ** 2 + 400 with boxes, x ** 2 + y ** 2 + 500 with vector
