#include "board.h"

RandomCell::RandomCell(int n)
    : board_size(n), rnd(std::random_device()()), dist(0, board_size-1){}

std::pair<int, int> RandomCell::operator()() {
    return {dist(rnd), dist(rnd)};
}