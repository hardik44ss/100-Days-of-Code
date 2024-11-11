"""
AIM: To demonstrate file handling operations in Python.


File Handling: File handling in Python refers to the process of reading from and writing to files on 
the file system. Python provides built-in functions and methods to perform various file operations,
allowing you to interact with files seamlessly.

Key Operations:
- Writing to a file: Open a file in write mode and write data to it.
- Reading from a file: Open a file in read mode and read its content.
- Appending to a file: Open a file in append mode and add data to it.
- Reading lines from a file: Read the file line by line.
- File information: Check if a file exists and get its size.
"""

import os

# Writing to a file
print("Writing to a file...")
with open("sample.txt", "w") as file:
    file.write("Hello, this is line 1.\n")  # Writing line 1
    file.write("This is line 2.\n")  # Writing line 2

# Reading from a file
print("\nReading from the file:")
with open("sample.txt", "r") as file:
    content = file.read()
    print(content)  # Output the content of the file

# Appending to a file
print("\nAppending to the file...")
with open("sample.txt", "a") as file:
    file.write("This is an appended line.\n")  # Appending a new line

# Reading lines from a file
print("\nReading lines from the file:")
with open("sample.txt", "r") as file:
    lines = file.readlines()
    for line in lines:
        print(line.strip())  # Output each line without extra newline characters

# File information
print("\nFile information:")
print(f"File exists: {os.path.exists('sample.txt')}")  # Check if file exists
print(f"File size: {os.path.getsize('sample.txt')} bytes")  # Output file size

print("\nNote: The 'sample.txt' file remains in your current directory.")