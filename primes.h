#ifndef PRIMES_H
#define PRIMES_H

#include <vector>
#include <set>

std::set<int> generate_primes(int UPPER_BOUND);
std::vector<std::pair<int, int>> prime_factorization(const std::set<int>& PRIMES, int n);

#endif //PRIMES_H
