#include <iostream>


#define PI 3.14159              // Basic macro definition
#define SQUARE(x) ((x) * (x))   // Macro with an argument
#define DEBUG 1                 // Macro for conditional compilation

#define MAX(a, b) \            
    ((a) > (b) ? (a) : (b))

int main() {
    // Using a basic macro
    std::cout << "Value of PI: " << PI << std::endl;

    // Using a macro with an argument
    int num = 5;
    std::cout << "Square of " << num << " is: " << SQUARE(num) << std::endl;

    // Demonstrating a common pitfall: SQUARE(1+2)
    std::cout << "Square of (1 + 2) is: " << SQUARE(1 + 2) << std::endl;
    // Here, the output might be unexpected because the macro expands to (1 + 2 * 1 + 2), which is 7 instead of 9.

    // Using a multi-line macro
    int a = 10, b = 20;
    std::cout << "Max of " << a << " and " << b << " is: " << MAX(a, b) << std::endl;

    // Conditional compilation using macros
    #if DEBUG
        std::cout << "Debug mode is ON" << std::endl;
    #else
        std::cout << "Debug mode is OFF" << std::endl;
    #endif

    return 0;
}
