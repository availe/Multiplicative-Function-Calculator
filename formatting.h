#ifndef FORMATTING_H
#define FORMATTING_H

#include <iostream>
#include <vector>
#include <ostream>

void check_length (size_t actual_size, int EXPECTED_SIZE);
void generate_header(const std::vector<std::string>& HEADER_LIST, std::ostream& output);
void generate_row(const std::vector<int>& row_data, size_t VECTOR_SIZE, std::ostream& output);

#endif //FORMATTING_H
