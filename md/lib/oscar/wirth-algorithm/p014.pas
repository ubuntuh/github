program p014(output);
var
    x: array[1..5] of integer = (2, 3, 5, 7, 9);
    y: array[1..5] of integer = (2, 3, 5, 7, 11);
begin
    writeln(x[1]);
    writeln((2, 3, 4, 7, 9) < (2, 3, 5, 7, 11));
    {writeln(x < y);}
    writeln('LABEL' < 'LIBEL');
end.

