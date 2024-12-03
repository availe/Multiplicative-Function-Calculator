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

    std::ofstream txt_file("output.txt");
    std::ofstream md_file("README.md");

    if (!txt_file || !md_file) {
        std::cerr << "Error: File(s) could not be opened." << std::endl;
        return 1;
    }


    std::vector<int> row_data;
    row_data.reserve(HEADER_LIST.size());

    if constexpr (LOWER_BOUND < 1) {
        throw std::invalid_argument("Error: Lower bound must be an integer equal or greater than 1.");
    }

    Multiplicative_Functions m;

    generate_header(HEADER_LIST, txt_file);
    generate_header_markdown(HEADER_LIST, md_file);
    for (int i = LOWER_BOUND; i <= UPPER_BOUND; ++i) {
        const std::vector<std::pair<int, int>> prime_factors = prime_factorization(PRIMES, i);
        m.set_prime_factors(prime_factors);

        row_data.emplace_back(i);
        row_data.emplace_back(m.num_of_divisors(i));
        row_data.emplace_back(m.sum_of_divisors(i));
        row_data.emplace_back(m.eulers_totient(i));
        row_data.emplace_back(m.tau_function(i));
        generate_row(row_data, HEADER_LIST.size(), txt_file);
        generate_row_markdown(row_data, HEADER_LIST.size(), md_file);
        row_data.clear();
    }

    return 0;
}
