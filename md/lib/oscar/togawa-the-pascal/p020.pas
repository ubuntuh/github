{---- 福利.pas ----}
program rei(input, output);
var
    a, r, n, y: real;
begin
    write('a, r, n = ');
    readln(a, r, n);
    y := a * exp(n * ln(1.0 + r / 100.0));
    writeln('答えは ', y);
end.

