{---- 級数.pas ----}
{ 級数の和の計算 }
program kyuusuu(input, output);
var
    i, n: integer;
    a, s: real;
begin
    write('n = ');
    readln(n);
    a := 1.0;
    s := 1.0;
    for i := 1 to n do
    begin
        a := a / i;
        s := s + a;
    end;
    write('第 n 項までの和は ', s : 15 : 7);
end.

