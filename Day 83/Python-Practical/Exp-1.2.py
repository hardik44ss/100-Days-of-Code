# AIM: To demonstrate the use of various operators, control structures, and statements in Python.
'''
Operators : It is used to perform operations on variables and values.
Arithmetic Operators : Basic mathematical operations like addition, subtraction, multiplication, division, etc.
Relational Operators : It is used to compare two values and return a boolean value.(e.g. >, <, ==, !=)
Logical Operators : It is used to perform boolean operations like AND, OR, NOT.

Control Structures : It is used to control the flow of execution in a program.
    if : It is used to execute a block of code only if a condition is true.
    else : It is used to execute a block of code if the condition is false.
    else if : It is used to check multiple conditions.


    break : It is used to exit the loop.
    continue : Used to skip the current iteration and continue with the next iteration.
    pass : null statement, used when a statement is required syntactically but you do not want any command or code to execute.

'''

# Operators example
print("Operators Example:")
a, b = 10, 3

# Arithmetic Operators
print(f"Arithmetic:")
print(f"{a} + {b} = {a + b}")   # Output: 10 + 3 = 13
print(f"{a} - {b} = {a - b}")   # Output: 10 - 3 = 7
print(f"{a} * {b} = {a * b}")   # Output: 10 * 3 = 30
print(f"{a} / {b} = {a / b}")   # Output: 10 / 3 = 3.3333333333333335 (True division)
print(f"{a} // {b} = {a // b}") # Output: 10 // 3 = 3 (Floor division)
print(f"{a} % {b} = {a % b}")   # Output: 10 % 3 = 1
print(f"{a} ** {b} = {a ** b}") # Output: 10 ** 3 = 1000

# Relational Operators
print(f"\nRelational:")
print(f"{a} > {b} is {a > b}")   # Output: 10 > 3 is True
print(f"{a} < {b} is {a < b}")   # Output: 10 < 3 is False
print(f"{a} == {b} is {a == b}") # Output: 10 == 3 is False
print(f"{a} != {b} is {a != b}") # Output: 10 != 3 is True

# Logical Operators
x, y = True, False
print(f"\nLogical:")
print(f"{x} and {y} is : {x and y}") # Output: True and False is False
print(f"{x} or {y} is : {x or y}")   # Output: True or False is True
print(f"not {x} is :  {not x}")       # Output: not True is False

# Control structures and transfer statements example
print("\nControl Structures and Transfer Statements Example:")

# if-else
num = 15
if num % 2 == 0:
    print(f"{num} is even")
else:
    print(f"{num} is odd")         # Output: 15 is odd

# for loop with break
print("\nFor loop with break:")
for i in range(5):
    if i == 3:
        break
    print(i, end=" ")              # Output: 0 1 2 
print()

# while loop with continue
print("\nWhile loop with continue:")
i = 0
while i < 5:
    i += 1
    if i == 3:
        continue
    print(i, end=" ")              # Output: 1 2 4 5 
print()

# pass statement
print("\nPass statement:")
for i in range(3):
    if i == 1:
        pass
    else:
        print(i, end=" ")          # Output: 0 2 
print()

# Pattern printing
print("\nPattern Printing:")
rows = 5
for i in range(rows):
    for j in range(i + 1):
        print("*", end="")
    print()                        
# Output: 
# *
# **
# ***
# ****
# *****
