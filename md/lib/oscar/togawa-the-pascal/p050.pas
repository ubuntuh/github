{ ---- 何歳 ---- }
program nansai(input, output);
var
    y: integer;
begin
    write('あなたは何歳ですか？ ');
    readln(y);
    if (y < 0) or (y >= 200)
    then
        writeln('まさかそんなことはないでしょう！');
end.

