#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <string>
#include <numeric>
#include <set>
#include <utility>

// table formatting functions

void check_length (const size_t actual_size, const int EXPECTED_SIZE) {
    if (actual_size != EXPECTED_SIZE) {
        throw std::invalid_argument("Error: Vector length does not match expected input.");
    }
}

void generate_header(const std::vector<std::string>& HEADER_LIST, const int VECTOR_SIZE) {
    check_length(HEADER_LIST.size(), VECTOR_SIZE);
    std::cout << "|";
    for (const std::string& entry : HEADER_LIST) {
        std::cout << std::setw(10) << entry << "|";
    }
    std::cout << "\n";}

void generate_row(const std::vector<int>& row_data, const int VECTOR_SIZE) {
    check_length(row_data.size(), VECTOR_SIZE);
    std::cout << "|";
    for (int number : row_data) {
        std::cout << std::setw(10) << number;
    }
    std::cout << "|\n";
}

// prime number functions

std::set<int> generate_primes(const int UPPER_BOUND) {
    if (UPPER_BOUND == 1) return {};

    std::vector<int> integer_list;
    integer_list.resize(UPPER_BOUND);
    // list every number from 1 to upperbound
    std::iota(integer_list.begin(), integer_list.end(), 2);

    std::set<int> non_primes;
    for (const int integer : integer_list) {
        if (integer <= 1) {
            non_primes.insert(integer);
            continue;
        }

        for (int divisor = 2; divisor < integer; divisor++) {
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
            counter++;
        }

        if (counter > 0) {
            result.emplace_back(prime, counter);
        }

        if (n == 0) return result;
    }
    return result;
}

int main()
{
    const int LOWER_BOUND = 1;
    const int UPPER_BOUND = 10;
    const int NUM_OF_COLS = 5;
    const std::set<int> PRIMES = generate_primes(UPPER_BOUND);
    const std::vector<std::string> HEADER_LIST = {"n", "d(n)", "σ(n)", "φ(n)", "τ(n)"};

    std::vector<int> row_data;
    row_data.reserve(NUM_OF_COLS);

    if constexpr (LOWER_BOUND < 1) {
        throw std::invalid_argument("Error: Lower bound must be an integer equal or greater than 1.");
    }

    generate_header(HEADER_LIST, NUM_OF_COLS);
    for (int i = LOWER_BOUND; i <= UPPER_BOUND; i++) {
        row_data.emplace_back(i);
        // generate_row(row_data, VECTOR_SIZE);
        prime_factorization(PRIMES, 5);
    }

    return 0;
}
