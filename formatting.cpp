#include "formatting.h"
#include <stdexcept>
#include <iomanip>

void check_length (const size_t actual_size, const size_t EXPECTED_SIZE) {
    if (actual_size != EXPECTED_SIZE) {
        throw std::invalid_argument("Error: Vector length does not match expected input.");
    }
}

void generate_header(const std::vector<std::string>& HEADER_LIST) {
    std::cout << "|";
    for (const std::string& entry : HEADER_LIST) {
        std::cout << std::setw(20) << entry << "|";
    }
    std::cout << "\n";}

void generate_row(const std::vector<int>& row_data, const size_t VECTOR_SIZE) {
    check_length(row_data.size(), VECTOR_SIZE);
    std::cout << "|";
    for (const int number : row_data) {
        std::cout << std::setw(20) << number;
    }
    std::cout << "|\n";
}