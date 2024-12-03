#include "formatting.h"
#include "multiplicative.h"
#include "primes.h"

#include <vector>
#include <stdexcept>
#include <string>
#include <set>
#include <fstream>

int main()
{
    constexpr int LOWER_BOUND = 1;
    constexpr int UPPER_BOUND = 256;
    const std::set<int> PRIMES = generate_primes(UPPER_BOUND);
    const std::vector<std::string> HEADER_LIST = {"n", "d(n)", "σ(n)", "φ(n)", "τ(n)"};

    std::ofstream file("output.txt");
    if (!file) {
        std::cerr << "Error: File could not be opened." << std::endl;
        return 1;
    }


    std::vector<int> row_data;
    row_data.reserve(HEADER_LIST.size());

    if constexpr (LOWER_BOUND < 1) {
        throw std::invalid_argument("Error: Lower bound must be an integer equal or greater than 1.");
    }

    Multiplicative_Functions m;

    generate_header(HEADER_LIST, file);
    for (int i = LOWER_BOUND; i <= UPPER_BOUND; ++i) {
        const std::vector<std::pair<int, int>> prime_factors = prime_factorization(PRIMES, i);
        m.set_prime_factors(prime_factors);

        row_data.emplace_back(i);
        row_data.emplace_back(m.num_of_divisors(i));
        row_data.emplace_back(m.sum_of_divisors(i));
        row_data.emplace_back(m.eulers_totient(i));
        row_data.emplace_back(m.tau_function(i));
        generate_row(row_data, HEADER_LIST.size(), file);
        row_data.clear();
    }

    return 0;
}
