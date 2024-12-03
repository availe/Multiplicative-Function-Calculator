#include "formatting.h"
#include <stdexcept>
#include <iomanip>

void check_length (const size_t actual_size, const size_t EXPECTED_SIZE) {
    if (actual_size != EXPECTED_SIZE) {
        throw std::invalid_argument("Error: Vector length does not match expected input.");
    }
}

void generate_header(const std::vector<std::string>& HEADER_LIST) {
    constexpr int BASE_WIDTH = 20;
    constexpr int EXTRA_WIDTH = BASE_WIDTH + 1;
    int counter = 0;

    std::cout << "|";
    for (size_t i = 0; i < HEADER_LIST.size(); ++i) {
        if (counter <= 1) {
            std::cout << std::setw(BASE_WIDTH);
            ++counter;
        }
        else {
            std::cout << std::setw(EXTRA_WIDTH);
        }
        std::cout << std::left << HEADER_LIST[i] << "|";
    }
    std::cout << "\n";
}

void generate_row(const std::vector<int>& row_data, const size_t VECTOR_SIZE) {
    check_length(row_data.size(), VECTOR_SIZE);
    constexpr int BASE_WIDTH = 20;

    std::cout << "|";
    for (const int number : row_data) {
        std::cout << std::setw(BASE_WIDTH) << std::left << number << "|";
    }
    std::cout << "\n";
}