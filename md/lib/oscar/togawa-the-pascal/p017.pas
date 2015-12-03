{ ---- en(2).pas ---- }
{ 円の面積 }
program en(input, output);
const
    pi = 3.1416;
var
    r, s: real;
begin
    write('r = ');
    readln(r);
    s := pi * r * r;
    writeln(' 面積は ', s : 15 : 7);
    writeln('alpha, beta, gamma, delta, epsilon, zeta, ');
    writeln('eta, theta, iota, kappa, lambda, mu, ');
    writeln('nu, ksi, omikron, pi, rho, sigma, ');
    writeln('tau, upsilon, phi, khi, psi, omega.');
end.

