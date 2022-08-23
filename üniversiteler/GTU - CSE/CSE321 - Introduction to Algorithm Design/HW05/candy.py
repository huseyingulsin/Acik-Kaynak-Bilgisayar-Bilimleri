from typing import List

# typical knapsack algorithm function
def candy_metric(prices : List[int], lengths : List[int], target : int) -> int:
    # create a matrix
    matrix = [[0] * (target + 1)] * (len(lengths) + 1)
    
    # fill the matrix
    for i in range(1, len(lengths) + 1):
        for j in range(1, target + 1):
            if lengths[i - 1] <= j:
                matrix[i][j] = max(matrix[i - 1][j], matrix[i - 1][j - lengths[i - 1]] + prices[i - 1])
            else:
                matrix[i][j] = matrix[i - 1][j]

    # return the maximum value
    return matrix[len(lengths)][target]


# Test
# --------------------- values ---------------------  weights ------------ W
print(candy_metric([1, 5, 8, 9, 10, 17, 17, 20], [1, 2, 3, 4, 5, 6, 7, 8], 8))
print(candy_metric([1, 5, 8, 9, 10, 17, 17, 20], [1, 2, 3, 4, 5, 6, 7, 8], 15))
print(candy_metric([1, 5, 7, 4, 1, 5, 14, 12], [1, 3, 4, 5, 5, 6, 7, 8], 10))

