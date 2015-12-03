{---- 福利.pas ----}
program rei(input, output);
var
    a, r, y: real;
    i, n: integer;
begin
    write('a, r, n = ');
    readln(a, r, n);
    y := a;
    for i := 1 to n do
        y := y * (1.0 + r / 100);
    writeln('答えは ', y : 10 : 0);
end.

