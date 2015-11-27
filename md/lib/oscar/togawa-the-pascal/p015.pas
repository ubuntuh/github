{---- 多項式.pas ----}
program rei(input, output);
var
    x, y: real;
begin
    write(' x = ');
    readln(x);
    y := ((2.0 * x + 5.0) * x + 3.0) * x + 1.0;
    writeln('y = ', y : 15 : 7);
end.

