# List Operations and Methods in Python: Short Definitions and Outputs

# 1. **List Creation**: Create lists with square brackets or list() function.
list1 = [1, 2, 3, 4, 5]
list2 = list((6, 7, 8, 9, 10))
print("List 1:", list1)   # Output: [1, 2, 3, 4, 5]
print("List 2:", list2)   # Output: [6, 7, 8, 9, 10]

# 2. **len()**: Returns the length of the list.
print("Length of list1:", len(list1))   
# Output: 5

# 3. **count()**: Counts occurrences of a specified element.
print("Count of 3 in list1:", list1.count(3))   
# Output: 1

# 4. **index()**: Finds the index of a specified element.
print("Index of 4 in list1:", list1.index(4))   
# Output: 3

# 5. **append()**: Adds an element to the end of the list.
list1.append(6)
print("After append:", list1)   
# Output: [1, 2, 3, 4, 5, 6]

# 6. **insert()**: Inserts an element at a specified position.
list1.insert(2, 2.5)
print("After insert:", list1)   
# Output: [1, 2, 2.5, 3, 4, 5, 6]

# 7. **extend()**: Adds elements from another list.
list1.extend([7, 8, 9])
print("After extend:", list1)   
# Output: [1, 2, 2.5, 3, 4, 5, 6, 7, 8, 9]

# 8. **remove()**: Removes the first occurrence of a specified element.
list1.remove(2.5)
print("After remove:", list1)   
# Output: [1, 2, 3, 4, 5, 6, 7, 8, 9]

# 9. **pop()**: Removes and returns an element (last by default).
list1.pop()
print("After pop:", list1)   
# Output: [1, 2, 3, 4, 5, 6, 7, 8]

# 10. **reverse()**: Reverses the list in place.
list1.reverse()
print("After reverse:", list1)   
# Output: [8, 7, 6, 5, 4, 3, 2, 1]

# 11. **sort()**: Sorts the list in ascending order.
list1.sort()
print("After sort:", list1)   
# Output: [1, 2, 3, 4, 5, 6, 7, 8]

# 12. **copy()**: Creates a shallow copy of the list.
list3 = list1.copy()
print("Copied list:", list3)   
# Output: [1, 2, 3, 4, 5, 6, 7, 8]

# 13. **clear()**: Removes all elements, resulting in an empty list.
list1.clear()
print("After clear:", list1)   
# Output: []

# 14. **Slicing**: Extracts a portion of the list.
print("Sliced list2:", list2[2:5])   
# Output: [8, 9, 10]
