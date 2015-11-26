{----- wasaint.pas -----}
{整数の和、差、積、商。}
program rei(input, output);
var
    a, b: integer;
    wa, sa, seki, shou: integer;
begin
    write('a = ');
    readln(a);
    write('b = ');
    readln(b);
    wa := a + b;
    sa := a - b;
    seki := a * b;
    shou := a div b;
    writeln('a + b = ', wa);
    writeln('a - b = ', sa);
    writeln('a * b = ', seki);
    writeln('a div b = ', shou);
end.

