{ ---- gas.pas ---- }
{ ---- ガソリンスタンド ---- }
program GAS(input, output);
var
    a, liter, kingaku: integer;
begin
    write('a = ');
    readln(a);
    writeln(' リッター ', ' 料金 ');
    for liter := 1 to 10 do
    begin
        kingaku := a * liter;
        writeln(liter : 5, kingaku : 7);
    end;
end.

