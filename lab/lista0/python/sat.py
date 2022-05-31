from z3 import *
x = Int("x")
y = Int("y")
s = Solver()
s.add(x == y + 1)
s.add(y == 2 * x)
print(s.check())
print(s.model())

