from typing import List

def mostProfitableCluster(array: List[int]) -> List[int]:
    maxProfit = 0;
    maxProfitCluster = []
    firstTime = True
    for i in range(len(array)):
        currentProfit = array[i]
        for j in range(i+1, len(array)):
            currentProfit += array[j]
            if firstTime or maxProfit < currentProfit:
                maxProfit = currentProfit
                firstTime = False
                maxProfitCluster = list(array[slice(i, j + 1)])
    
    # return max profit cluster
    return maxProfitCluster

cluster = mostProfitableCluster([3,-5,2,11,-8,9,-5])
print(cluster)
    

# find most valuable item in given array with divide and conquer
def mostProfitableItem(array: List[int]) -> int:
    if len(array) == 1:
        return array[0]
    else:
        mid = len(array) // 2
        left = mostProfitableItem(array[:mid])
        right = mostProfitableItem(array[mid:])
        return max(left, right)

print(mostProfitableItem(cluster))