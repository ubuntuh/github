program p014_2(input, output);
const
    N = 4;
type
    Ints = array[1..N] of integer;
function search(arr: Ints; key: integer): integer;
    var
        i: integer;
    begin
    i := 0;
    repeat i := i + 1 until (arr[i] = key) or (i = N);
    if arr[i] <> key then
        writeln('There is no such element in the array.')
    else
        writeln('Index = ', i);
    search := 0;
end;
var
    a: Ints;
    inp: integer;
begin
    write('Key = ');
    readln(inp);
    a[1] := 10;
    a[2] := 20;
    a[3] := 30;
    a[4] := 40;
    search(a, inp);
end.

