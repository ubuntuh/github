program Hilbert(pf, output);
{plot Hilbert curves of orders 1 to n}
const
    n = 4;
    h0 = 512;
var
    i, h, x, y, x0, y0: integer;
    pf: file of integer;
procedure A(i: integer);
begin
    if i > 0 then
    begin
        D(i - 1);
        x := x - h;
        plot;
        A(i - 1);
        y := y - h;
        plot;
        A(i - 1);
        x := x + h;
        plot;
        B(i - 1);
    end
end;
procedure B(i: integer);
begin
    if i > 0 then
    begin
        C(i - 1);
        y := y + h;
        plot;
        B(i - 1);
        x := x + h;
        plot;
        B(i - 1);
        y := y - h;
        plot;
        A(i - 1);
    end
end;
procedure C(i: integer);
begin
    if i > 0 then
    begin
        B(i - 1);
        x := x + h;
        plot;
        C(i - 1);
        y := y + h;
        plot;
        C(i - 1);
        x := x - h;
        plot;
        D(i - 1);
    end
end;
procedure D(i: integer);
begin
    if i > 0 then
    begin
        A(i - 1);
        y := y - h;
        plot;
        D(i - 1);
        x := x - h;
        plot;
        D(i - 1);
        y := y + h;
        plot;
        C(i - 1);
    end
end;
begin startplot;
    i := 0;
    h := h0;
    x0 := h div 2;
    y0 := x0;
    repeat
        i := i + 1;
        h := h div 2;
        x0 := x0 + (h div 2);
        y0 := y0 + (h div 2);
        x := x0;
        y := y0;
        setplot;
        A(i);
    until i = n;
    endplot;
end.

