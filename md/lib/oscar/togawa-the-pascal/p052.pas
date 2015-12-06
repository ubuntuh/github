{ ---- 二次根.pas ---- }
{ 2 次方程式の根の計算 }
program nijikon(input, output);
var
    a, b, c, d, s, t, x1, x2: real;
begin
    write(' a, b, c = ');
    readln(a, b, c);
    d := b * b - 4.0 * a * c;
    s := sqrt(abs(d)) / (2.0 * a);
    t := - b / (2.0 * a);
    if d > 0.0 then begin
        writeln('x1 = ', t + s);
        writeln('x2 = ', t - s);
    end else begin
        if d = 0.0 then
            writeln('x := ', t)
        else begin
            writeln('x1 = ', t : 15 : 7, '  +  ', s : 15 : 7, 'i');
            writeln('x := ', t : 15 : 7, '  -  ', s : 15 : 7, 'i');
        end;
    end;
end.

