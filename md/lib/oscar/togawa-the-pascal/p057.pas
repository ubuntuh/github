{ ---- 素数.pas ---- }
{ 素数表を作る }
const
    n = 1000;
var
    a: array[1..n] of integer;
    i, j, made: integer;
begin
    for i := 1 to n do
        a[i] := 0;
    for i := 2 to n do begin
        if a[i] = 0 then begin
            write(i : 5);
            made := n div i;
            for j := 2 to made do
                a[i * j] := 1;
        end;
    end;
end.

