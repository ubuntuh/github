program p009(output);
var
    x, y, z: integer;
    p, q: boolean;
begin
    x := 5;
    y := 8;
    z := 10;
    p := x = y;
    q := (x < y) and (y <= z);
    writeln('p = ', p);
    writeln('q = ', q);
end.

