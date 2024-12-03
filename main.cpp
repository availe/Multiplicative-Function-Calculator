#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <numeric>
#include <set>
#include <utility>

#include "formatting.h"
#include "multiplicative.h"
#include "primes.h"

int main()
{
    const int LOWER_BOUND = 1;
    const int UPPER_BOUND = 10;
    const std::set<int> PRIMES = generate_primes(UPPER_BOUND);
    const std::vector<std::string> HEADER_LIST = {"n", "d(n)", "σ(n)", "φ(n)", "τ(n)"};

    std::vector<int> row_data;
    row_data.reserve(HEADER_LIST.size());

    if constexpr (LOWER_BOUND < 1) {
        throw std::invalid_argument("Error: Lower bound must be an integer equal or greater than 1.");
    }
    std::vector<std::pair<int, int>> prime_factors = prime_factorization(PRIMES, 88);

    Multiplicative_Functions m;
    m.set_prime_factors(prime_factors);


    generate_header(HEADER_LIST);
    for (int i = LOWER_BOUND; i <= UPPER_BOUND; i++) {
        row_data.emplace_back(m.num_of_divisors(i));
        row_data.emplace_back(m.sum_of_divisors(i));
        row_data.emplace_back(m.eulers_totient(i));
        row_data.emplace_back(m.tau_function(i));
        generate_row(row_data, HEADER_LIST.size());
        row_data.clear();
    }

    return 0;
}
