#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <string>
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

// std::vector<std::pair<int, int>> prime_factorization(const int n) {

// }


int main()
{
    const int LOWER_BOUND = 1;
    const int UPPER_BOUND = 10;
    const int VECTOR_SIZE = 5;
    const std::vector<std::string> HEADER_LIST = {"n", "d(n)", "σ(n)", "φ(n)", "τ(n)"};

    std::vector<int> row_data;
    row_data.reserve(VECTOR_SIZE);

    if (LOWER_BOUND < 1) {
        throw std::invalid_argument("Error: Lower bound must be an integer equal or greater than 1.");
    }

    generate_header(HEADER_LIST, VECTOR_SIZE);
    for (int i = LOWER_BOUND; i <= UPPER_BOUND; i++) {
        row_data.emplace_back(i);
        // generate_row(row_data, VECTOR_SIZE);
    }

    return 0;
}