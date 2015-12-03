program p014(output);
var
    x: array[1..5] of integer = (1, 2, 3, 4, 5);
    y: array[1..5] of integer = (1, 2, 3, 4, 6);
begin
    writeln(x[1]);
    writeln(x < y);
end.

