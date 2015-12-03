{ ---- 数表.pas ---- }
{ 2 乗、逆数、平方根の数表 }
program suuhyou(output);
var
    n: integer;
begin
    writeln('n 2 乗 逆数 平方根');
    for n := 1 to 10 do
    begin
        write(n : 2);
        write(n * n : 7);
        write(1.0 / n : 8 : 5);
        writeln(sqrt(n) : 8 : 5);
    end;
end.

