program p012(output);
type
    Row = array[1..5] of real;
    Card = array[1..80] of char;
    alfa = array[1..10] of char;
    LetterValues = array['A'..'Z'] of integer;
    Rank = (private, corporal, sergeant, lieutenant, captain, major, colonel, general);
    OfficerValues = array[lieutenant..general] of integer;
var
    x: Row;
    lv: LetterValues;
    ov: OfficerValues;
begin
    {x := real(1.1, 2.2, 3.3, 4.4, 5.5);}
    x[1] := 0.125;
    writeln(x[1]);
    lv['Z'] := 10;
    writeln(lv['Z']);
    ov[lieutenant] := 20;
    writeln(ov[lieutenant]);
end.

