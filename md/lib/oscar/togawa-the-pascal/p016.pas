{ ---- en(1).pas ---- }
{ 円の面積 }
program en(input, output);
var
    r, s: real;
begin
    write('r = ');
    readln(r);
    s := 3.1416 * r * r;
    writeln(' 面積は ', s : 15 : 7);
end.

