

# take exponent of a number with divide and conquer
def exponent(base : int, exp : int) -> int:
    if (exp == 0):
        return 1
    elif (exp == 1):
        return base
    else:
        if (exp % 2 == 0):
            return exponent(base, exp // 2) * exponent(base, exp // 2)
        else:
            return base * exponent(base, (exp - 1) // 2) * exponent(base, (exp - 1) // 2)


# take exponent of a number with brute force
def exponent_brute(base : int, exp : int) -> int:
    if (exp == 0):
        return 1
    else:
        result = 1
        for _ in range(exp):
            result *= base
        return result

# test
print(exponent(2, 3))
print(exponent(2, 4))
print(exponent(2, 5))
print(exponent(2, 30))

print(exponent_brute(2, 3))
print(exponent_brute(2, 4))
print(exponent_brute(2, 5))
print(exponent_brute(2, 30))