/*
Experiment 1: Fetching Complexity of a Recurrence Relation

Key Points:
********  Recursion Realation : T(n) = a*T(n/b) + n^c           ********
- This program calculates the time complexity of recurrence relations of the form T(n) = a*T(n/b) + n^c.
- It uses the Master Theorem to determine the complexity based on the values of a, b, and c.
Master Theorem:
-T(n) = a*T(n/b) + f(n), where a >= 1, b > 1, and f(n) is a given function.

- Complexity cases:
  1. If c < log_b(a), then T(n) = Θ(n^(log_b(a))).
  2. If c = log_b(a), then T(n) = Θ(n^(log_b(a)) * log(n)).
  3. If c > log_b(a), then T(n) = Θ(n^c).
  
- Inputs: a, b, and c where a >= 1 and b > 1 for valid complexity calculations.
*/

#include <iostream>
#include <cmath>
using namespace std;

/*
AIM: To determine the time complexity of a recurrence relation using the Master Theorem.

The Master Theorem provides a solution to recurrence relations of the form:
T(n) = a*T(n/b) + n^k

Inputs:
- a: Coefficient of the subproblem count (a >= 1)
- b: Factor by which the subproblem size is divided (b > 1)
- c: Exponent of the polynomial term

The algorithm calculates the time complexity based on the values of a, b, and c.
*/

// Function to determine the time complexity using the Master Theorem
void getComplexity(int a, int b, int k) {
    // Calculate log_b(a)
    double log_b_a = log(a) / log(b);

    // Compare c with log_b(a) to determine the time complexity
    if (k < log_b_a) {
        cout << "T(n) = Θ(n^" << log_b_a << ")\n";
    } else if (k == log_b_a) {
        cout << "T(n) = Θ(n^" << log_b_a << " * log(n))\n";
    } else {
        cout << "T(n) = Θ(n^" << k << ")\n";
    }
} 

int main() {
    int a = 2;
    int b = 2;
    int c = 1;

    // Validate the inputs
    if (a < 1 || b <= 1) {
        cerr << "Invalid input. 'a' must be >= 1 and 'b' must be > 1.\n";
        return 1;
    }

    // Determine the time complexity
    getComplexity(a, b, c);

    return 0;
}

/*
Expected Output:
T(n) = Θ(n^1 * log(n))
*/