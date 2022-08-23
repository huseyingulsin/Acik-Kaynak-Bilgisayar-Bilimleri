
def findPolynomial(a : int, n : int, x : int) -> int:
    result = 0
    for i in range(n+1):
        result += a * x**i
    return result

print(findPolynomial(5, 3, 2))
print(findPolynomial(3, 3, 2))
print(findPolynomial(2, 3, 2))