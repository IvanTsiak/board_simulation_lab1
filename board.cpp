#include "board.h"
#include <set>

RandomCell::RandomCell(int n)
    : board_size(n), rnd(std::random_device()()), dist(0, board_size-1){}

std::pair<int, int> RandomCell::operator()() {
    return {dist(rnd), dist(rnd)};
}

void run_experiment(int n, int m, int trials) {
    Board board(n);
    RandomCell generator(m);
    Statistics stats;
    for (int i=0; i<trials-1; i++) {
        board.clear();
        std::set<std::pair<int, int>> selected_cells;
        for (int k=0; k<m; k++) {
            selected_cells.insert(generator());
        }
        for (const auto &cell : selected_cells) {
            board.mark_cell(cell.first, cell.second);
            std::vector<std::pair<int, int>> neighbors = Board::get_neighbors(cell.first, cell.second);
            for (const auto &neighbor : neighbors) {
                board.mark_cell(neighbor.first, neighbor.second);
            }
        }
    }
}