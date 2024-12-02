#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <numeric>
#include <set>
#include <utility>

#include "formatting.h"
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

    generate_header(HEADER_LIST);
    for (int i = LOWER_BOUND; i <= UPPER_BOUND; i++) {
        row_data.emplace_back(i);
        // generate_row(row_data, VECTOR_SIZE);
        prime_factorization(PRIMES, 5);
    }

    return 0;
}
