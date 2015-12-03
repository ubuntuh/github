{---- 売り上げ.pas ----}
program uriage(input, output);
var
    i, n, total: integer;
    tanka, suuryo, kingaku: integer;
begin
    write('n = ');
    readln(n);
    total := 0;
    writeln('    単価 数量 金額');
    for i := 1 to n do
    begin
        write(' ? ');
        readln(tanka, suuryo);
        kingaku := tanka * suuryo;
        writeln(tanka : 17, suuryo : 11, kingaku : 11);
        total := total + kingaku;
    end;
    writeln('----');
    writeln('    金額の合計は ', total : 8);
end.

