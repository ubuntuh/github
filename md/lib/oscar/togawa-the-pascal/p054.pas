program uruu(input, output);
var y: integer;
begin
    write('y = ');
    readln(y);
    if ((y mod 4) = 0)
        and ((y mod 100) <> 0)
        or  ((y mod 400) =  0) then
            writeln('閏年である。')
        else
            writeln('閏年ではない。');
end.

