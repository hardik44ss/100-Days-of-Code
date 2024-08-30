class Solution {
public:
    bool checkPerfectNumber(int num) {
         if (num <= 1) {
        return false;
    }

    int sum_of_divisors = 1;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            sum_of_divisors += i + num / i;
        }
    }

    return sum_of_divisors == num;
    }
};