"""
String: Sequence of characters enclosed in single, double, or triple quotes. Strings are immutable in Python.

String Indexing: Access individual characters in a string using their index (positive for left-to-right, negative for right-to-left).

String Slicing: Extract specific parts of a string using a range of indices, with optional start, stop, and step values.

String Methods: Built-in methods allow various string operations (e.g., strip, upper, lower, find, replace).

find() and replace():
   - find(): Returns the starting index of the specified substring; -1 if not found.
   - replace(): Replaces occurrences of a specified substring with another substring.

split() and join():
   - split(): Splits the string into a list of words or substrings.
   - join(): Joins elements of a list into a single string with a specified separator.

Useful Methods: isalnum(), startswith(), and endswith() for string validation and checking.

String Formatting: Format strings using .format() or f-strings to embed variables within a string.
"""


#---------------Code Starts Here-----------------#
text = "  Hello, Python Programming! "
print("Original string:", text)  # Original string:   Hello, Python Programming! 
print("Length of the string:", len(text))  # Length of the string: 28

# Indexing
print("\nIndexing:")
print("First character:", text[0])  # First character:  
print("Last character:", text[-1])  # Last character:  

# Slicing
print("\nSlicing:")
print("First 5 characters:", text[:5])  # First 5 characters:   Hel
print("Last 5 characters:", text[-5:])  # Last 5 characters: ming!
print("Characters from index 7 to 13:", text[7:14])  # Characters from index 7 to 13: Hello, 

# String methods
print("\nString methods:")
print("Stripped string:", text.strip())  # Stripped string: Hello, Python Programming!
print("Uppercase:", text.upper())        # Uppercase:   HELLO, PYTHON PROGRAMMING! 
print("Lowercase:", text.lower())        # Lowercase:   hello, python programming! 

# find() and replace()
print("\nfind() and replace():")
print("Index of 'Python':", text.find("Python"))                            # Index of 'Python': 9
print("Replacing 'Python' with 'Java':", text.replace("Python", "Java"))    # Replacing 'Python' with 'Java':   Hello, Java Programming! 

# split() and join()
print("\nsplit() and join():")
words = text.split()
print("Split into words:", words)               # Split into words: ['Hello,', 'Python', 'Programming!']
print("Joined with hyphens:", "-".join(words))  # Joined with hyphens: Hello,-Python-Programming!

# Other useful methods
print("\nOther methods:")
print("Is alphanumeric?", text.strip().isalnum())  # Is alphanumeric? False
print("Starts with 'Hello'?", text.strip().startswith("Hello")) # Starts with 'Hello'? True
print("Ends with '!'?", text.strip().endswith("!"))             # Ends with '!'? True

# Formatting
name = "ABC"
age = 30
print("\nFormatting:")
print("Using .format(): My name is {} and I'm {} years old.".format(name, age))
print(f"Using f-string: My name is {name} and I'm {age} years old.")
