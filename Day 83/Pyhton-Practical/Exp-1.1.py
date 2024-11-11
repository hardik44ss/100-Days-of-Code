# AIM: To demonstrate the basics of Python programming and understand   fundamental data types and functions.
'''
id() : It returns a unique id (or memory address) of an object.
type() : It returns the type of an object.(e.g. int, float, str, list, tuple, dict, etc.)

int : To store integer values.(or Whole numbers without decimal point)
float : To store floating point values.(or Real numbers with decimal point)

range() : It used in for loop to generate a sequence of numbers.

1. What is Python?
Python is an interpreted, high-level, general-purpose programming language. It emphasizes code readability and supports multiple programming paradigms, including procedural, object-oriented, and functional programming.

2. What are Python’s key features?
    Key features include:
    Easy-to-read syntax.
    Dynamically typed.
    Interpreted language.
    Extensive standard library.
    Supports object-oriented, functional, and imperative programming.
    Cross-platform compatibility.

3. What is the difference between Python 2 and Python 3?
    -Python 3 is the future version of Python. Major differences include:
    -Print is a function in Python 3 (print()) vs a statement in Python 2.
    -Integer division returns a float in Python 3 (5 / 2 = 2.5) 
    vs
     integer in Python 2 (5 / 2 = 2).
    -Unicode support in Python 3 by default.




'''
# Different data types
a = 10        # int
b = 20.5      # float
c = 1 + 2j    # complex
d = True      # bool
e = "Hello"   # string
 
# Using id() and type() functions
print("ID of a:", id(a))
print("Type of a:", type(a))
print("ID of b:", id(b))
print("Type of b:", type(b))
print("ID of c:", id(c))
print("Type of c:", type(c))
print("ID of d:", id(d))
print("Type of d:", type(d))
print("ID of e:", id(e))
print("Type of e:", type(e))

#Another datatypes
lt = [1, 2, 3] # list
tp = (1, 2, 3) # tuple
dt = {1:'one', 2:'two'} # dictionary*
st = {1, 2, 3} # set

 
# Using range() function
for i in range(5):
    print("Value of i:", i)

''' Output:
ID of a: 140728393206488
Type of a: <class 'int'>
ID of b: 2242451669808
Type of b: <class 'float'>
ID of c: 2242448174864
Type of c: <class 'complex'>
ID of d: 140728392405584
Type of d: <class 'bool'>
ID of e: 2242451577312
Type of e: <class 'str'>

Value of i: 0
Value of i: 1
Value of i: 2
Value of i: 3
Value of i: 4

'''
