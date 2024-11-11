
# Tuple Creation, Accessing, and Operations in Python

# 1. **Creating Tuples**: Tuples are immutable sequences in Python.
print("Creating tuples:")
empty_tuple = ()  # Empty tuple
single_item_tuple = (42,)  # Tuple with one item (note the comma)
mixed_tuple = (1, "two", 3.0, True)  # Mixed data types
nested_tuple = (1, (2, 3), [4, 5])  # Nested tuple

print("Empty tuple:", empty_tuple)  # Output: ()
print("Single item tuple:", single_item_tuple)  # Output: (42,)
print("Mixed tuple:", mixed_tuple)  # Output: (1, 'two', 3.0, True)
print("Nested tuple:", nested_tuple)  # Output: (1, (2, 3), [4, 5])

# 2. **Accessing Tuple Elements**: Access elements using indexing.
print("\nAccessing tuple elements:")
print("First item of mixed_tuple:", mixed_tuple[0])  # Output: 1
print("Last item of mixed_tuple:", mixed_tuple[-1])  # Output: True
print("Nested item:", nested_tuple[1][0])  # Output: 2

# 3. **Slicing Tuples**: Extract sub-tuples using slicing.
print("\nSlicing tuples:")
numbers = (0, 1, 2, 3, 4, 5)
print("Original tuple:", numbers)  # Output: (0, 1, 2, 3, 4, 5)
print("First three items:", numbers[:3])  # Output: (0, 1, 2)
print("Last three items:", numbers[-3:])  # Output: (3, 4, 5)
print("Every second item:", numbers[::2])  # Output: (0, 2, 4)

# 4. **Tuple Operations**: Perform operations like concatenation, repetition, etc.
print("\nTuple operations:")
tuple1 = (1, 2, 3)
tuple2 = (4, 5, 6)

# Concatenation
concatenated = tuple1 + tuple2
print("Concatenated tuple:", concatenated)  # Output: (1, 2, 3, 4, 5, 6)

# Repetition
repeated = tuple1 * 3
print("Repeated tuple:", repeated)  # Output: (1, 2, 3, 1, 2, 3, 1, 2, 3)

# Length
print("Length of tuple1:", len(tuple1))  # Output: 3

# Membership test
print("Is 3 in tuple1?", 3 in tuple1)  # Output: True
print("Is 7 in tuple1?", 7 in tuple1)  # Output: False

# Min and Max
print("Minimum value in tuple1:", min(tuple1))  # Output: 1
print("Maximum value in tuple1:", max(tuple1))  # Output: 3

# 5. **Count and Index**: Count occurrences and find index of elements.
sample_tuple = (1, 2, 2, 3, 2, 4, 5)
print("\nSample tuple:", sample_tuple)  # Output: (1, 2, 2, 3, 2, 4, 5)
print("Count of 2 in sample_tuple:", sample_tuple.count(2))  # Output: 3
print("Index of first occurrence of 2:", sample_tuple.index(2))  # Output: 1

# 6. **Tuple Unpacking**: Assign tuple values to variables.
print("\nTuple unpacking:")
x, y, z = tuple1
print(f"Unpacked values: x = {x}, y = {y}, z = {z}")  # Output: x = 1, y = 2, z = 3

# 7. **Tuple Comparison**: Compare tuples.
print("\nTuple comparison:")
print("(1, 2, 3) == (1, 2, 3):", (1, 2, 3) == (1, 2, 3))  # Output: True
print("(1, 2, 3) < (1, 2, 4):", (1, 2, 3) < (1, 2, 4))  # Output: True

# 8. **Converting Between Tuples and Lists**: Convert tuples to lists and vice versa.
print("\nConverting between tuples and lists:")
tuple_to_list = list(tuple1)
print("Tuple converted to list:", tuple_to_list)  # Output: [1, 2, 3]
list_to_tuple = tuple(tuple_to_list)
print("List converted back to tuple:", list_to_tuple)  # Output: (1, 2, 3)
