# Demonstrating Sets and Dictionaries in Python

print("Sets and Dictionaries")
print("================================")

# Sets
print("\nSets:")
print("------")

# Creating sets
fruits = {"apple", "banana", "cherry", "date"}
vegetables = set(["carrot", "broccoli", "spinach"])
numbers = {1, 2, 3, 4, 5}

print("Fruits set:", fruits)  # Output: {'apple', 'banana', 'cherry', 'date'}
print("Vegetables set:", vegetables)  # Output: {'carrot', 'broccoli', 'spinach'}
print("Numbers set:", numbers)  # Output: {1, 2, 3, 4, 5}

# Set operations
print("\nSet Operations:")
more_fruits = {"banana", "elderberry", "fig"}
print("More fruits:", more_fruits)  # Output: {'banana', 'elderberry', 'fig'}

# Union
print("Union of fruits and more_fruits:", fruits.union(more_fruits))  # Output: {'apple', 'banana', 'cherry', 'date', 'elderberry', 'fig'}
 
# Intersection
print("Intersection of fruits and more_fruits:", fruits.intersection(more_fruits))  # Output: {'banana'}
 
# Difference
print("Difference between fruits and more_fruits:", fruits.difference(more_fruits))  # Output: {'cherry', 'date', 'apple'}
 
# Symmetric difference
print("Symmetric difference of fruits and more_fruits:", fruits.symmetric_difference(more_fruits))  # Output: {'elderberry', 'fig', 'cherry', 'date', 'apple'}

# Adding and removing elements
fruits.add("grape")
print("After adding 'grape':", fruits)  # Output: {'apple', 'banana', 'cherry', 'date', 'grape'}
fruits.remove("apple")
print("After removing 'apple':", fruits)  # Output: {'banana', 'cherry', 'date', 'grape'}

# Checking membership
print("Is 'cherry' in fruits?", "cherry" in fruits)  # Output: True

# Dictionaries
print("\nDictionaries:")
print("--------------")

# Creating dictionaries
person = {"name": "John", "age": 30, "city": "New York"}
scores = dict(math=85, science=92, history=78)

print("Person dictionary:", person)  # Output: {'name': 'John', 'age': 30, 'city': 'New York'}
print("Scores dictionary:", scores)  # Output: {'math': 85, 'science': 92, 'history': 78}

# Accessing and modifying values
print("\nAccessing and Modifying:")
print("John's age:", person["age"])  # Output: 30
person["age"] = 31
print("Updated age:", person["age"])  # Output: 31

# Adding new key-value pairs
person["occupation"] = "Engineer"
print("After adding occupation:", person)  # Output: {'name': 'John', 'age': 31, 'city': 'New York', 'occupation': 'Engineer'}

# Dictionary methods
print("\nDictionary Methods:")
print("Keys:", person.keys())  # Output: dict_keys(['name', 'age', 'city', 'occupation'])
print("Values:", person.values())  # Output: dict_values(['John', 31, 'New York', 'Engineer'])
print("Items:", person.items())  # Output: dict_items([('name', 'John'), ('age', 31), ('city', 'New York'), ('occupation', 'Engineer')])

# Get method with default value
print("Trying to get 'phone':", person.get("phone", "Not available"))  # Output: Not available

# Removing items
removed_item = person.pop("city")
print("Removed item:", removed_item)  # Output: New York
print("After removing 'city':", person)  # Output: {'name': 'John', 'age': 31, 'occupation': 'Engineer'}

# Dictionary comprehension
squared_numbers = {x: x**2 for x in range(1, 6)}
print("\nSquared numbers dictionary:", squared_numbers)  # Output: {1: 1, 2: 4, 3: 9, 4: 16, 5: 25}

# Nested dictionaries
students = {
    "Alice": {"age": 20, "major": "Computer Science"},
    "Bob": {"age": 22, "major": "Physics"}
}
print("\nNested dictionary - Students:", students)  # Output: {'Alice': {'age': 20, 'major': 'Computer Science'}, 'Bob': {'age': 22, 'major': 'Physics'}}
print("Bob's major:", students["Bob"]["major"])  # Output: Physics
