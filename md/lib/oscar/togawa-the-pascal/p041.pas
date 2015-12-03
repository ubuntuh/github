{---- 分散.pas ----}
{ 平均値と標準偏差 }
program p041(input, output);
var
    x: array[1..100] of real;
    i, n: integer;
    s, ss, heikin, bunsan, sigma: real;
begin
    write('n = ');
    readln(n);
    for i := 1 to n do
    begin
        write('x(', i : 2, ') = ');
        readln(x[i]);
    end;
    s := 0.0;
    for i := 1 to n do
        s := s + x[i];
    heikin := s / n;
    ss := 0.0;
    for i := 1 to n do
        ss := ss + sqr(x[i] - heikin);
    bunsan := ss / n;
    sigma := sqrt(bunsan);
    writeln('平均値は ', heikin : 15 : 7);
    writeln('分散は ', bunsan : 15 : 7);
    writeln('標準偏差は ', sigma : 15 : 7);
end.

