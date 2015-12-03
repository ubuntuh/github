program p011(output);
function f(c: char): integer;
begin
    f := ord(c) - ord('0');
end;
function g(i: integer): char;
begin
    g := chr(i + ord('0'));
end;
begin
    writeln('ord(''A'') = ', ord('A'));
    writeln('ord(''a'') = ', ord('a'));
    writeln('chr(65) = ', chr(65));
    writeln('chr(97) = ', chr(97));
    writeln('f(''3'') = ', f('3'));
    writeln('g(5) = ', g(5));
end.

