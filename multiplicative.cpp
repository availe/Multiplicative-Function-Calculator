#include "multiplicative.h"
#include <cmath>

int Multiplicative_Functions::num_of_divisors(int n) {
    int num_of_divisors = 1; // 1 is not prime but always a divisor
    for (const auto& [prime, exponent] : prime_factors) {
        num_of_divisors *= (exponent + 1);
    }

    return num_of_divisors;
}

int Multiplicative_Functions::sum_of_divisors(int n) {

    int sum_of_divisors = 1;
    for (const auto& [prime, exponent] : prime_factors) {
        const int numerator = static_cast<int>(pow(prime, exponent + 1) - 1);
        const int denominator = prime - 1;
        sum_of_divisors += numerator / denominator;
    }

    return sum_of_divisors;
}

