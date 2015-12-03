{---- LEQ.pas ----}
{ 連立 1 次方程式を解く }
program p044(input, output);
const nn = 10;
var
    a: array[1..nn, 1..nn] of real;
    b, x: array[1..nn] of real;
    p, q, s: real;
    i, j, k, n: integer;
begin
    { データの読み込み }
    write('n := ');
    readln(n);
    writeln('係数行列と右辺');
    for i := 1 to n do
    begin
        write(i : 3, ' 行目');
        for j := 1 to n do
        begin
            write(' ');
            read(a[i, j]);
        end;
        write(' | ');
        readln(b[i]);
    end;
    { 消去法 }
    writeln('前進消去');
    for k := 1 to n - 1 do
    begin
        write(k : 2);
        p := a[k, k];
        for j := k + 1 to n do
            a[k, j] := a[k, j] / p;
        b[k] := b[k] / p;
        for i := k + 1 to n do
        begin
            q := a[i, k];
            for j := k + 1 to n do
                a[i, j] := a[i,j] - q * a[k, j];
            b[i] := b[i] - q * b[k];
        end;
    end;
    writeln;
    writeln('後退代入');
    x[n] := b[n] / a[n, n];
    for k := n - 1 downto 1 do
    begin
        write(k : 2);
        s := b[k];
        for j := k + 1 to n do
            s := s - a[k, j] * x[j];
        x[k] := s;
    end;
    { 結果の表示 }
    writeln;
    writeln(' 解 ');
    for i := 1 to n do
        writeln('x(', i : 2, ')=', x[i]);
end.

