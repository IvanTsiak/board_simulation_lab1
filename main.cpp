#include <iostream>
#include "board.h"

int main() {
    int n = 20;
    int trials = 1000;

    std::vector<int> values = {10, 20, 50, 100, 200};

    std::cout << "\nn=" << n << "\ntrials=" << trials << std::endl;

    for (int m : values) {
        std::cout << "\nm = " << m << " :\n";
        run_experiment(n, m, trials);
    }

    return 0;
}