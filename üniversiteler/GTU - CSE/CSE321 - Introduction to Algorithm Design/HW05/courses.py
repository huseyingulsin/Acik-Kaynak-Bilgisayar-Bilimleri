from typing import List
import math

# this also could be improved

# sort 2d array by column
def sort_by_column(arr : List[List[int]]):
    return sorted(arr, key=lambda x: x[1])

def max_courses(courses : List[List[int]]) -> int:
    sortedCourses = sort_by_column(courses)

    max_count = 0
    end_time = -math.inf

    for course in sortedCourses:
        if course[0] >= end_time:
            max_count += 1
            end_time = course[1]
    
    return max_count

# Test
print(max_courses([[1, 2], [3, 4], [0, 6], [5, 7], [8, 9], [5, 9]]))
print(max_courses([[3, 4], [1, 2], [4, 8], [5, 9], [9, 10]]))