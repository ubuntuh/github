expr = x**2 - x - 6
display(expr)
display(expr.factor())
display(solve(expr))
divisors12 = FiniteSet(*divisors(12))
divisors24 = FiniteSet(*divisors(24))
display(divisors12)
display(divisors24)
print('is_subset = ' + str(divisors12.is_subset(divisors24)))
