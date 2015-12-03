{ ---- 大口.pas ---- }
{ 大口割引 }
program GAS(input, output);
const
    a = 118.;
    b = 20.;
    c = 0.1;
var
    liter, kingaku, k1, k2: real;
begin
    write('liter = ');
    readln(liter);
    if liter < b
    then
        kingaku := a * liter
    else
    begin
        k1 := a * b;
        k2 := a * (liter - b) * (1.0 - c);
        kingaku := k1 + k2;
    end;
    writeln('金額は ', kingaku : 7 : 0, ' 円');
end.

