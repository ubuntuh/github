{ ---- minmax.pas ---- }
program minmax(input, output);
var
    a: array[1..100] of real;
    i, n: integer;
    saidai, saisho: real;
begin
    { 入力 }
    write('n = ');
    readln(n);
    for i := 1 to n do begin
        write('a(', i : 3, ') = ');
        readln(a[i]);
    end;
    { 最大最小を求める }
    saidai := a[1];
    saisho := a[1];
    for i := 2 to n do begin
        if a[i] > saidai then saidai := a[i];
        if a[i] < saisho then saisho := a[i];
    end;
    { 出力 }
    writeln(' 最大値 ', saidai : 15 : 7);
    writeln(' 最小値 ', saisho : 15 : 7);
end.

