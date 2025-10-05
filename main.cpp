// Compiler: MSVC
// Authors (K-24): Ivan Tsiak, Andriy Sushchenko
#include <iostream>
#include "board.h"

int main() {
    size_t n = 20;
    size_t trials = 800;

    std::vector<size_t> values = {10, 20, 50, 100, 200};

    std::cout << "\nn = " << n << "\ntrials = " << trials << std::endl;

    try {
        for (size_t m : values) {
            std::cout << "\nm = " << m << " :\n";
            run_experiment(n, m, trials);
        }
    } catch (const std::invalid_argument &e) {
        std::cout << "Invalid argument: " << e.what() << std::endl;
        return 0;
    } catch (...) {
        std::cout << "Somethig went wrong!" << std::endl;
        return 0;
    }

    return 0;
}