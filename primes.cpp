#include "primes.h"
#include <numeric>

std::set<int> generate_primes(const int UPPER_BOUND) {
    if (UPPER_BOUND == 1) return {};

    std::vector<int> integer_list;
    integer_list.resize(UPPER_BOUND);
    // list every number from 2 to upperbound
    std::iota(integer_list.begin(), integer_list.end(), 2);

    std::set<int> non_primes;
    for (const int integer : integer_list) {
        if (integer <= 1) {
            non_primes.insert(integer);
            continue;
        }

        for (int divisor = 2; divisor < integer; ++divisor) {
            if (integer % divisor == 0) {
                non_primes.insert(integer);
                break;
            }
        }
    }

    std::set<int> primes;
    for (int num : integer_list) {
        if (!non_primes.contains(num)) {
            primes.insert(num);
        }
    }

    return primes;
}

std::vector<std::pair<int, int>> prime_factorization(const std::set<int>& PRIMES, int n) {
    if (n == 1) return {};

    std::vector<std::pair<int, int>> result;

    if (PRIMES.contains(n)) {
        result.emplace_back(n, 1);
        return result;
    }

    for (const int prime : PRIMES) {
        int counter = 0;
        while (n % prime == 0) {
            n /= prime;
            ++counter;
        }

        if (counter > 0) {
            result.emplace_back(prime, counter);
        }

        if (n == 0) return result;
    }
    return result;
}