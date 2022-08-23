from typing import List, Tuple

# find best and worst in a list with divide and conquer function
def min_max(lst : List[int]) -> Tuple[int, int]:
    if len(lst) == 1:
        return (lst[0], lst[0])
    else:
        mid = len(lst) // 2
        left = min_max(lst[:mid])
        right = min_max(lst[mid:])
        return (min(left[0], right[0]), max(left[1], right[1]))

# test
print(min_max([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))
print(min_max([10, 9, 8, 7, 6, 5, 4, 3, 2, 1]))
print(min_max([15,6,4,33,4,5,12,5,6,7,8,3,5,2]))
