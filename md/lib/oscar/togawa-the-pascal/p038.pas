{---- 合計 ----}
program goukei(input, output);
var
    a: array[1..100] of real;
    i, n: integer;
    s: real;
begin
    write('n := ');
    readln(n);
    for i := 1 to n do
    begin
        write('a(', i : 3, ') = ');
        readln(a[i]);
    end;
    s := 0.0;
    for i := 1 to n do
        s := s + a [i];
    writeln('合計は ', s : 11 : 5);
end.

