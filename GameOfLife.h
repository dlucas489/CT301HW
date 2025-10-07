#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <string>

class GameOfLife {
private:
    int width;
    int height;
    int generation;
    std::string board;

    int countLiveNeighbors(int row, int col) const;
    int index(int row, int col) const { return row * width + col; }

public:
    GameOfLife(int w, int h, const std::string& gameString);
    void next();
    void nextNGen(int n);
    void printGame() const;
};

#endif
