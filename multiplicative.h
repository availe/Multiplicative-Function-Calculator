#ifndef MULTIPLICATIVE_H
#define MULTIPLICATIVE_H
#include <vector>

class Multiplicative_Functions {
public:
    int num_of_divisors(int n);
    int sum_of_divisors(int n);
    int eulers_totient(int n);
    int tau_function(int n);

    void set_prime_factors(const std::vector<std::pair<int,int>>& prime_factors) {
        this->prime_factors = prime_factors;
    }

private:
    std::vector<std::pair<int, int>> prime_factors;
};

#endif //MULTIPLICATIVE_H
