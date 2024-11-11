"""
AIM: To demonstrate searching and sorting algorithms in Python.

Linear Search: Sequentially checks each element in a list until the target element 
        is found or the end is reached.

Binary Search: Efficiently finds the position of a target value within a sorted array 
        by repeatedly dividing the search interval in half.

Selection Sort: Divides the input list into a sorted sublist and an unsorted sublist, 
        and repeatedly selects the smallest element from the unsorted sublist to add 
        to the sorted sublist.

Bubble Sort: Repeatedly steps through the list, compares adjacent elements, and swaps 
        them if they are in the wrong order.

Insertion Sort: Builds the final sorted list one element at a time by repeatedly 
        inserting the next element into the correct position.

Merge Sort: Follows the divide-and-conquer strategy by dividing the input list into 
        smaller sublists, sorting each sublist recursively, and then merging 
        the sorted sublists.

Quick Sort: Efficiently sorts by selecting a "pivot" element and partitioning the 
        other elements into two sublists based on whether they are less than or 
        greater than the pivot.
"""

import random
import time

def linear_search(arr, target):
    """Linear Search: Sequentially checks each element until the target is found."""
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

def binary_search(arr, target):
    """Binary Search: Efficiently finds the target in a sorted array by dividing the search interval in half."""
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

def selection_sort(arr):
    for i in range(len(arr)):
        min_idx = i
        for j in range(i + 1, len(arr)):
            if arr[min_idx] > arr[j]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        L = arr[:mid]
        R = arr[mid:]

        merge_sort(L)
        merge_sort(R)

        i = j = k = 0

        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1

        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1

    return arr

def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]
        less = [x for x in arr[1:] if x <= pivot]
        greater = [x for x in arr[1:] if x > pivot]
        return quick_sort(less) + [pivot] + quick_sort(greater)

def test_algorithm(func, arr, *args):
    start_time = time.time()
    result = func(arr.copy(), *args)
    end_time = time.time()
    return result, end_time - start_time

# Example usage
if __name__ == "__main__":
    # Generate a random list of integers
    arr = [random.randint(0, 100) for _ in range(10)]
    target = arr[random.randint(0, 9)]

    print("Array:", arr)
    print("Target:", target)

    # Linear Search
    start_time = time.time()
    result = linear_search(arr, target)
    end_time = time.time()
    print(f"Linear Search: Index of target ({target}) is {result}, Time taken: {end_time - start_time:.6f} seconds")

    # Binary Search (requires sorted array)
    arr.sort()
    start_time = time.time()
    result = binary_search(arr, target)
    end_time = time.time()
    print(f"Binary Search: Index of target ({target}) is {result}, Time taken: {end_time - start_time:.6f} seconds")

# Generate a random array for testing
arr = [random.randint(1, 1000) for _ in range(1000)]
target = arr[random.randint(0, len(arr) - 1)]

print("Searching Algorithms:")
print("---------------------")
linear_result, linear_time = test_algorithm(linear_search, arr, target)
print(f"Linear Search: Found {target} at index {linear_result}. Time: {linear_time:.6f} seconds")

sorted_arr = sorted(arr)
binary_result, binary_time = test_algorithm(binary_search, sorted_arr, target)
print(f"Binary Search: Found {target} at index {binary_result}. Time: {binary_time:.6f} seconds")

print("\nSorting Algorithms:")
print("-------------------")
for sort_func in [bubble_sort, insertion_sort, selection_sort, merge_sort, quick_sort]:
    _, sort_time = test_algorithm(sort_func, arr)
    print(f"{sort_func.__name__}: Time: {sort_time:.6f} seconds")

print("\nVerifying sorted arrays:")
for sort_func in [bubble_sort, insertion_sort, selection_sort, merge_sort, quick_sort]:
    sorted_arr, _ = test_algorithm(sort_func, arr)
    print(f"{sort_func.__name__}: {'Correctly sorted' if sorted_arr == sorted(arr) else 'Incorrectly sorted'}")