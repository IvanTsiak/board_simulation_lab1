#pragma once
#include <iostream>
#include <vector>
#include <random>

class RandomCell {
private:
    int board_size;
    std::mt19937 rnd;
    std::uniform_int_distribution<> dist;
public:
    RandomCell(int n);
    std::pair<int, int> operator()();
};

class Board {
private:
    int size;
    std::vector<std::vector<bool>> cells;
public:
    Board(int size);
    void mark_cell(int row, int col);
    int get_free_zone_size();
    bool is_valid_cell(int row, int col);
    void clear();
};

class Statistics {
private:
    std::vector<int> m_results;
public:
    void add_result(int result);
    double mean();
    double median();
    void print_summary();
};

void run_experiment();