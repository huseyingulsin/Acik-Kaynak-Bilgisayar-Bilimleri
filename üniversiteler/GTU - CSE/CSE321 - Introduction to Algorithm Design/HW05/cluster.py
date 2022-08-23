from typing import List
import math

# find the maximum profit interval in a list
def max_profit(prices : List[int]) -> int:
    max_profit = -math.inf
    cur_profit = -math.inf
    for price in prices:
        cur_profit = max(price, cur_profit + price)
        max_profit = max(max_profit, cur_profit)

    return int(max_profit)

# test
print(max_profit([3, -5, 2, 11, -8, 9, -5]))
print(max_profit([1, 2, 3, 4, 5]))
print(max_profit([7, 6, 4, 3, 1]))
print(max_profit([7, 1, -10, 3, 6, 4]))