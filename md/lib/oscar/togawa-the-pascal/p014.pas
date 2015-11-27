{---- bunsuu.pas ----}
{ b / a と d / c の和、差、積、商の計算。}
program bunsuu(input, output);
var
    a, b, c, d: integer;
    bunsi, bunbo: integer;
begin
    write(' a = ');
    readln(a);
    write(' b = ');
    readln(b);
    write(' c = ');
    readln(c);
    write(' d = ');
    readln(d);
    bunsi := b * c + a * d;
    bunbo := a * c;
    writeln('(b / a) + (d / c) = ', bunsi, ' / ', bunbo);
    bunsi := b * c - a * d;
    writeln('(b / a) - (d / c) = ', bunsi, ' / ', bunbo);
    bunsi := b * d;
    writeln('(b / a) * (d / c) = ', bunsi, ' / ', bunbo);
    bunsi := b * c;
    bunbo := a * d;
    writeln('(b / a) / (d / c) = ', bunsi, ' / ', bunbo);
end.

