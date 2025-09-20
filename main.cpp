#include <iostream>
#include <board.h>
int main() {
    int n = 8;
    int m = 4;
    int trials = 100000;

    std::cout << "n=" << n << std::endl << "m=" << m << std::endl << "trials=" << trials << std::endl;

    run_experiment(n, m, trials);

    return 0;
}