{----- wasaseki.pas -----}
program rei(input, output);
var
    a, b: real;
    wa, sa, seki, shou: real;
begin
    write('a, b  = ');
    readln(a, b);
    wa := a + b;
    sa := a - b;
    seki := a * b;
    shou := a / b;
    writeln('a + b = ', wa);
    writeln('a - b = ', sa);
    writeln('a * b = ', seki);
    writeln('a / b = ', shou);
    writeln('a + b = ', wa:10:5);
    writeln('a - b = ', sa:10:5);
    writeln('a * b = ', seki:10:5);
    writeln('a / b = ', shou:10:5);
end.

