#include "GameOfLife.h"
#include <iostream>

GameOfLife::GameOfLife(int w, int h, const std::string& gameString)
    : width(w), height(h), generation(0), board(gameString) {}

int GameOfLife::countLiveNeighbors(int row, int col) const {
    int count = 0;
    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            if (dr == 0 && dc == 0) continue;
            int r = row + dr;
            int c = col + dc;
            if (r >= 0 && r < height && c >= 0 && c < width) {
                if (board[index(r, c)] == '1') ++count;
            }
        }
    }
    return count;
}

void GameOfLife::next() {
    std::string newBoard = board;
    for (int r = 0; r < height; ++r) {
        for (int c = 0; c < width; ++c) {
            int neighbors = countLiveNeighbors(r, c);
            char cell = board[index(r, c)];
            if (cell == '1') {
                newBoard[index(r, c)] = (neighbors == 2 || neighbors == 3) ? '1' : '0';
            } else {
                newBoard[index(r, c)] = (neighbors == 3) ? '1' : '0';
            }
        }
    }
    board = newBoard;
    ++generation;
}

void GameOfLife::nextNGen(int n) {
    if (n <= 0) return;
    for (int i = 0; i < n; ++i) next();
}

void GameOfLife::printGame() const {
    std::cout << "Generation: " << generation << '\n';
    for (int r = 0; r < height; ++r)
        std::cout << board.substr(r * width, width) << '\n';
}
