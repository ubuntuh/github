{---- HMS.pas ----}
program HMS(input, output);
var
    h1, m1, s1, h2, m2, s2: integer;
    b1, b2, b, a, h, m, s: integer;
begin
    write('始めの時刻を H M S の順に入れてください ');
    readln(h1, m1, s1);
    write('終わりの時刻を H M S の順に入れてください ');
    readln(h2, m2, s2);
    b1 := 3600 * h1 + 60 * m1 + s1;
    b2 := 3600 * h2 + 60 * m2 + s2;
    b := b2 - b1;
    h := b div 3600;
    a := b mod 3600;
    m := a div 60;
    s := a mod 60;
    writeln('経過時間は ');
    writeln(h, ' 時間');
    writeln(m, ' 分');
    writeln(s, ' 秒');
end.

