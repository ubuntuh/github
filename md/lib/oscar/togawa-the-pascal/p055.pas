program HMS60(input, output);
var
    h1, m1, s1, h2, m2, s2: integer;
    b1, b2, b, a, h, m, s: integer;
begin
    write('始めの時刻を H M S の順に入れてください ');
    readln(h1, m1, s1);
    write('終わりの時刻を H M S の順に入れてください ');
    readln(h2, m2, s2);
    s := s2 - s1;
    if s < 0 then begin
        s := s + 60;
        m2 := m2 - 1;
    end;
    m := m2 - m1;
    if m < 0 then begin
        m := m + 60;
        h2 := h2 - 1;
    end;
    h := h2 - h1;
    if h >= 0 then begin
        writeln(' 経過時間は ');
        writeln(h, ' 時間');
        writeln(m, ' 分');
        writeln(s, ' 秒');
    end;
end.

