# AIM: To demonstrate the use of functions, parameter types, variable scope, and lambda functions in Python.
'''
Local Variables: Defined within a function and accessible only within that function.
Global Variables: Defined outside all functions and accessible throughout the program.

Function : A block of code that performs a specific task.(def keyword is used to define a function)
    Syntax : def function_name(parameters):

Positional Parameters: These are required arguments that must be passed in the correct order.
Default Parameters: These have default values and are optional when calling the function (e.g., b=10 in demo_function).]

Variable-Length Arguments (*args and **kwargs):
    *args allows passing multiple positional arguments as a tuple.
    **kwargs allows passing multiple keyword arguments as a dictionary.


Lambda Functions : small anonymous fun. that can have any number of arguments, but can only have one expression.
    Syntax : lambda arguments : expression

'''
import calendar
from datetime import datetime, timedelta

# Global variable
global_var = "Global"

def demo_function(a, b=10, *args, **kwargs):
    """Demonstrates function arguments and scope."""
    local_var = "Local"
    print(f"Arguments: a={a}, b={b}, args={args}, kwargs={kwargs}")
    print(f"Variables: local={local_var}, global={global_var}")
    return "Function completed"

# Main program
print("1. Function demonstration:")
result = demo_function(5, 20, 30, 40, key1="value1")
print(f"Result: {result}\n")
# Output:
# 1. Function demonstration:
# Arguments: a=5, b=20, args=(30, 40), kwargs={'key1': 'value1'}
# Variables: local=Local, global=Global
# Result: Function completed

# Modifying global variable
global_var = "Modified Global"
print(f"\nModified global variable: {global_var}")
# Output:
# Modified global variable: Modified Global

# Lambda function
add = lambda x, y: x + y

print("2. Lambda function:")
print(f"5 + 3 = {add(5, 3)}\n")
# Output:
# 2. Lambda function:
# 5 + 3 = 8

# Date functions
get_future_date = lambda days: datetime.now() + timedelta(days=days)

print("3. Date calculations:")
future = get_future_date(30)
print(f"Date after 30 days: {future.strftime('%Y-%m-%d')}\n")
# Output:
# 3. Date calculations:
# Date after 30 days: (date after 30 days from current date)

show_calendar = lambda year, month: print(calendar.month(year, month))

print("4. Calendar:")
current_year, current_month = datetime.now().year, datetime.now().month
show_calendar(current_year, current_month)
# Output:
# 4. Calendar:
# (Displays the calendar of the current month and year)


'''
datetime:   provides classes for handling dates and times in Python.
timedelta:  represents a duration, which can be added to datetime objects to get future or past dates 
            (e.g., get_future_date = lambda days: datetime.now() + timedelta(days=days)).

Calendar Functions: The calendar module allows displaying and working with monthly and yearly calendars (e.g., calendar.month).
'''

