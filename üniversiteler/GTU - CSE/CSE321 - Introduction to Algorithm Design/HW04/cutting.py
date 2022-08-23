import math

# a function that divides n length wire to 1 length wire with minimum cut
def min_cut(n : int) -> int:
    if n == 1:
        return 0
    else:
        return 1 + min_cut(math.ceil(n / 2))

# test
print(min_cut(5))
print(min_cut(8))
print(min_cut(100))