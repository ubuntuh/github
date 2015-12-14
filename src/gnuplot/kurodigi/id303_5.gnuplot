set term png
set output "output.png"
# http://stackoverflow.com/questions/10397750/embedding-multiple-datasets-in-a-gnuplot-command-script
splot "-" with vector
# M-x electric-indent-mode
# http://stackoverflow.com/questions/5666443/how-should-i-format-my-dat-file-so-that-a-3d-vector-plot-can-be-made
# Px    Py    Pz    Bx    By    Bz
  0     0     0     0.8   0.8   0.45
  0     0     1     0.5   0.7   0.35
  0     0     2     0.7   0.5   0.25
  0     1     0     0.65   0.65   0.50
  0     1     1     0.6   0.6   0.3
  0     1     2     0.45   0.45   0.20
  1     0     0     0.5   0.7   0.35
  1     0     1     0.75   0.75   0.4
  1     0     2     0.85   0.85   0.25
  1     1     0     0.90   0.85   0.23
  1     1     1     0.95   0.86   0.20
  1     1     2     0.98   0.88   0.13
  2     0     0     0.73   0.83   0.43
  2     0     1     0.53   0.73   0.33
  2     0     2     0.73   0.53   0.23
  2     1     0     0.68   0.68   0.52
  2     1     1     0.63   0.57   0.23
  2     1     2     0.48   0.42   0.22
