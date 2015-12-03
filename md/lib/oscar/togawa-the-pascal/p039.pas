{---- pascal.pas ----}
program pascal(input, output);
var
    k: array[1..8, 1..8] of integer;
    i, j, n: integer;
begin
    n := 8;
    k[1, 1] := 1;
    for i := 2 to n - 1 do
    begin
        k[i, 1] := 1;
        k[i, i] := 1;
        for j := 2 to i do
            k[i + 1, j] := k[i, j - 1] + k[i, j];
    end;
    for i := 1 to n - 1 do
    begin
        for j := 1 to n - i do
            write('   ');
        for j := 1 to i do
            write(k[i, j] : 6);
        writeln;
    end;
end.

