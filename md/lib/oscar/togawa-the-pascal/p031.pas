{ ---- 合計 (1) ---- }
program goukei(input, output);
var
    i, n: integer;
    a, s: real;
begin
    write('n := ');
    readln(n);
    s := 0.0;
    for i := 1 to n do
    begin
        write('  ? ');
        readln(a);
        s := s + a;
    end;
    writeln('合計は ', s : 11 : 5);
end.

