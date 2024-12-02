#ifndef FORMATTING_H
#define FORMATTING_H

#include <iostream>
#include <vector>

void check_length (size_t actual_size, int EXPECTED_SIZE);
void generate_header(const std::vector<std::string>& HEADER_LIST);
void generate_row(const std::vector<int>& row_data, int VECTOR_SIZE);

#endif //FORMATTING_H
