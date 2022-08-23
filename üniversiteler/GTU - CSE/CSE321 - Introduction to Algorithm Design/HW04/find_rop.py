from typing import List


# a divide function
def _merge_like(lst : List[int], low : int, high : int) -> int:
    if (low >= high):
        return 0

    mid = low + (high - low) // 2

    left = _merge_like(lst, low, mid)
    right = _merge_like(lst, mid + 1, high)

    mergeResult = merge_like(lst, low, mid, high)

    return left + right + mergeResult

def merge_like(lst : List[int], leftInd : int, midInd : int, rightInd : int) -> int:
    leftLst = lst[leftInd:midInd + 1]
    rightLst = lst[midInd + 1: rightInd + 1]

    i = 0
    j = 0
    k = leftInd
    count = 0

    while (i < len(leftLst) and j < len(rightLst)):
        if (leftLst[i] <= rightLst[j]):
            lst[k] = leftLst[i]
            i += 1
        else:
            lst[k] = rightLst[j]
            j += 1
            count += midInd + 1 - leftInd - i
        k += 1
        
    while (j < len(rightLst)):
        lst[k] = rightLst[j]
        j += 1
        k += 1

    while (i < len(leftLst)):
        lst[k] = leftLst[i]
        i += 1
        k += 1
    
    return count

def reversePairCount(lst : List[int]) -> int:
    return _merge_like(lst, 0, len(lst) - 1)


# test
print(reversePairCount([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))
print(reversePairCount([5,1,2,3,4]))
print(reversePairCount([10, 9, 8, 7, 6, 5, 4, 3, 2, 1]))
print(reversePairCount([15,6,4,33,4,5,12,5,6,7,8,3,5,2]))