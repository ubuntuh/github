{---- 余り.pas ----}
program rei(input, output);
var
    m, n, q, r: integer;
begin
    write('m = ');
    readln(m);
    write('n = ');
    readln(n);
    q := m div n;
    r := m mod n;
    writeln('商は ', q);
    writeln('余りは ', r);
end.

