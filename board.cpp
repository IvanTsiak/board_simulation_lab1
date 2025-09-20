#include "board.h"
#include <set>
#include <stdexcept>
#include <algorithm>

RandomCell::RandomCell(int n)
    : board_size(n), rnd(std::random_device()()), dist(0, board_size-1){}

std::pair<int, int> RandomCell::operator()() {
    return {dist(rnd), dist(rnd)};
}

void run_experiment(int n, int m, int trials) {
    Board board(n);
    RandomCell generator(n);
    Statistics stats;
    for (int i=0; i<trials; i++) {
        board.clear();
        std::set<std::pair<int, int>> selected_cells;
        for (int k=0; k<m; k++) {
            selected_cells.insert(generator());
        }
        for (const auto &cell : selected_cells) {
            board.mark_cell(cell.first, cell.second);
            std::vector<std::pair<int, int>> neighbors = board.get_neighbors(cell.first, cell.second);
            for (const auto &neighbor : neighbors) {
                board.mark_cell(neighbor.first, neighbor.second);
            }
        }
        stats.add_result(board.get_free_zone_size());
    }
    stats.print_summary();
}


//class Board
Board::Board(int size) : size(size), cells(size, std::vector<bool>(size, false)) {
    if (size <= 0) {
        throw std::invalid_argument("Board size must be > 0");
    }
}

void Board::clear() {
    for (auto &row : cells) {
        std::fill(row.begin(), row.end(), false);
    }
}

bool Board::is_valid_cell(int row, int col) {
    return row >= 0 && row < size && col >= 0 && col < size;
}

std::vector<std::pair<int, int>> Board::get_neighbors(int row, int col) {
    std::vector<std::pair<int, int>> neighbors;

    for (int r = -1; r <= 1; r++) {
        for (int c = -1; c <= 1; c++) {
            if (r == 0 && c == 0) {
                continue;
            }
            int new_r = row + r;
            int new_c = col + c;
            if (is_valid_cell(new_r, new_c)) {
                neighbors.emplace_back(new_r, new_c);
            }
        }
    }

    return neighbors;
}


void Board::mark_cell(int row, int col) {
    if (is_valid_cell(row, col)) {
        cells[row][col] = true;
    }
}

int Board::get_free_zone_size() {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (!cells[i][j]) {
                count++;
            }
        }
    }
    return count;
}


//class Statistics
void Statistics::add_result(int result) {
    m_results.push_back(result);
}

double Statistics::mean() {
    if (m_results.empty()) return 0.0;
    double sum = 0.0;
    for (int value : m_results) {
        sum += value;
    }
    return sum / m_results.size();
}

double Statistics::median() {
    if (m_results.empty()) return 0.0;
    std::vector<int> sorted = m_results;
    std::sort(sorted.begin(), sorted.end());
    size_t n = sorted.size();
    if (n % 2 == 1) {
        return sorted[n / 2];
    } else {
        return (sorted[n / 2 - 1] + sorted[n / 2]) / 2.0;
    }
}

void Statistics::print_summary() {
    std::cout << "Mean free zone: " << mean() << "\n";
    std::cout << "Median free zone: " << median() << "\n";
}