#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <random>

class RandomCell {
private:
    size_t board_size;
    std::mt19937 rnd;
    std::uniform_int_distribution<> dist;
public:
    RandomCell(size_t b_size);
    std::pair<int, int> operator()();
};

class Board {
private:
    size_t size;
    std::vector<std::vector<bool>> cells;
public:
    Board(size_t size);
    void mark_cell(int row, int col);
    int get_free_zone_size() const;
    bool is_valid_cell(int row, int col) const;
    void clear();
    std::vector<std::pair<int, int>> get_neighbors(int row, int col) const;
};

class Statistics {
private:
    std::vector<int> m_results;
public:
    void add_result(int result);
    double mean() const;
    double median() const;
    void print_summary() const;
};

void run_experiment(size_t board_size, size_t num_sel_cells, size_t trials);