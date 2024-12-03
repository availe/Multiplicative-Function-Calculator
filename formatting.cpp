#include "formatting.h"
#include <stdexcept>
#include <iomanip>

void check_length (const size_t actual_size, const size_t EXPECTED_SIZE) {
    if (actual_size != EXPECTED_SIZE) {
        throw std::invalid_argument("Error: Vector length does not match expected input.");
    }
}

void generate_header(const std::vector<std::string>& HEADER_LIST, std::ostream& output) {
    constexpr int BASE_WIDTH = 20;
    constexpr int EXTRA_WIDTH = BASE_WIDTH + 1;
    int counter = 0;

    output << "|";
    for (size_t i = 0; i < HEADER_LIST.size(); ++i) {
        if (counter <= 1) {
            output << std::setw(BASE_WIDTH);
            ++counter;
        }
        else {
            output << std::setw(EXTRA_WIDTH);
        }
        output << std::left << HEADER_LIST[i] << "|";
    }
    output << "\n";
}

void generate_row(const std::vector<int>& row_data, const size_t VECTOR_SIZE, std::ostream& output) {
    check_length(row_data.size(), VECTOR_SIZE);
    constexpr int BASE_WIDTH = 20;

    output << "|";
    for (const int number : row_data) {
        output << std::setw(BASE_WIDTH) << std::left << number << "|";
    }
    output << "\n";
}

void generate_header_markdown(const std::vector<std::string>& HEADER_LIST, std::ostream& output) {
    output << "|";
    for (const std::string& header : HEADER_LIST) {
        output << " " << header << " |";
    }
    output << "\n|";
    for (size_t i = 0; i < HEADER_LIST.size(); ++i) {
        output << "---|";
    }
    output << "\n";
}

void generate_row_markdown(const std::vector<int>& row_data, const size_t VECTOR_SIZE, std::ostream& output) {
    check_length(row_data.size(), VECTOR_SIZE);
    output << "|";
    for (const int number : row_data) {
        output << " " << number << " |";
    }
    output << "\n";
}
