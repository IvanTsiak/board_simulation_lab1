#include <iostream>
#include "board.h"

int main() {
    int n = 20;
    int trials = 1000;

    std::vector<int> values = {10, 20, 50, 100, 200};

    std::cout << "\nn=" << n << "\ntrials=" << trials << std::endl;

    try {
        for (int m : values) {
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