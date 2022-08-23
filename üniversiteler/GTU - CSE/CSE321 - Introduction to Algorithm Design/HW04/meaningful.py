from typing import List

# find smallest in a list
def min_in_list(lst : List[int]) -> int:
    if len(lst) == 1:
        return lst[0]
    else:
        mid = len(lst) // 2
        left = min_in_list(lst[:mid])
        right = min_in_list(lst[mid:])
        return min(left, right)

# call min_in_list kth times and remove the smallest k times
def remove_kth_smallest(lst : List[int], k : int) -> List[int]:
    if k == 0:
        return lst
    else:
        smallest = min_in_list(lst)
        lst.remove(smallest)
        return remove_kth_smallest(lst, k - 1)

# find kth biggest element
def kth_biggest(lst : List[int], k : int) -> int:
    remove_kth_smallest(lst, k - 1)
    return min_in_list(lst)
        

# test
print(kth_biggest([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 5))
print(kth_biggest([10, 9, 8, 7, 6, 5, 4, 3, 2, 1], 5))
print(kth_biggest([15,6,4,33,4,5,12,5,6,7,8,3,5,2], 2))