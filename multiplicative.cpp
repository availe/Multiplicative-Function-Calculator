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
        sum_of_divisors *= numerator / denominator;
    }

    return sum_of_divisors;
}

/** eulers_totient equals n ∏ [1 - (1 / prime)]
 *
 * But we must take floating numbers and integer division into account with C++
 * φ(n) = n ∏ [1 - (1/p)]
 * φ(n) = φ(n) [1 - (1/p)]
 * φ(n) = φ(n) [(p-1)/p]
 * φ(n) = [φ(n)(p-1)]/p
 **/

int Multiplicative_Functions::eulers_totient(int n) {
    int eulers_totient = n;
    for (const auto& [prime, exponent] : prime_factors) {
        eulers_totient = (eulers_totient * (prime - 1)) / prime;
    }

    return eulers_totient;
}

int Multiplicative_Functions::tau_function(int n) {
    const size_t num_distinct_prime_factors = prime_factors.size();
    return static_cast<int>(pow(-1, num_distinct_prime_factors));
}


