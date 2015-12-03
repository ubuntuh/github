{---- SCT.pas ----}
program rei(input, output);
var
    s, c, t, theta, x: real;
begin
    write('theta = ');
    readln(theta);
    x := theta * 3.141593 / 180.0;
    s := sin(x);
    c := cos(x);
    t := s / c;
    writeln('sin(theta) = ', s : 15 : 7);
    writeln('cos(theta) = ', c : 15 : 7);
    writeln('tan(theta) = ', t : 15 : 7);
    writeln('abs(x) 絶対値');
    writeln('sqr(x) ２乗');
    writeln('sqrt(x) 平方根');
    writeln('ln(x) 自然対数');
    writeln('exp(x) 指数関数');
    writeln('sin(x) 三角関数（角度はラジアン）');
    writeln('con(x) 三角関数');
    writeln('arctan(x) 逆正接');
    writeln('trunc(x) 小数点以下切り捨て');
    writeln('round(x) 四捨五入して整数にする');
    writeln('int(x) 整数部');
    writeln('frac(x) 小数部');
    writeln(int(2.3));
    writeln(frac(2.3));
end.

