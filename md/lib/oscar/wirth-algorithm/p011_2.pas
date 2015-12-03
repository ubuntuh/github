program p011_2(output);
type
    year = 1900..1999;
    letter = 'A'..'Z';
    digit = '0'..'9';
    rank = (private, corporal, sergeant, lieutenant, captain, major, colonel, general);
    officer = lieutenant..general;
var
    y: year;
    L: letter;
begin
    y := 1973;
    {y := 1291;}
    L := 'W';
    {L := '9';}
    writeln(y);
    writeln(L);
end.

