program p007(output);
type
    shape = (rectangle, square, ellipse, circle);
    color = (red, yellow, green);
    sex = (male, female);
    {Boolean = (false, true);}
    weekday = (Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday);
    currency = (franc, mark, pound, dollar, shilling, lira, guilder, krone, ruble, cruzeiro, yen);
    destination = (hell, purgatory, heaven);
    vehicle = (train, bus, automobile, boat, airplane);
    rank = (private, corporal, sergeant, lieutenant, captain, major, colonel, general);
    {object = (constant, type, variable, procedure, function);}
    {structure = (file, array, record, set);}
    condition = (manual, unloaded, parity, skew);
var
    s: sex;
    d: weekday;
    r: rank;
    b: Boolean;
begin
    s := male;
    d := Sunday;
    r := major;
    b := true;
    writeln(s);
    writeln(d);
    writeln(r);
    writeln(b);
end.

