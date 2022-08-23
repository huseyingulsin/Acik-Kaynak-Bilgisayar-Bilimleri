from typing import List

# knapsack algorithm with greedy approach
def cheese_metric(p : List[int], w : List[int], W : int) -> int:
    n = len(p)
    if n == 0:
        return 0
    if W == 0:
        return 0
    if w[0] > W:
        return cheese_metric(p[1:], w[1:], W)
    else:
        return max(p[0] + cheese_metric(p[1:], w[1:], W - w[0]), cheese_metric(p[1:], w[1:], W))

print(cheese_metric([1, 5, 8, 9, 10, 17, 17, 20], [1, 2, 3, 4, 5, 6, 7, 8], 8))
print(cheese_metric([1, 5, 8, 9, 10, 17, 17, 20], [1, 2, 3, 4, 5, 6, 7, 8], 15))
print(cheese_metric([1, 5, 7, 4, 1, 5, 14, 12], [1, 3, 4, 5, 5, 6, 7, 8], 10))

