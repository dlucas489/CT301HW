#include "parser.h"
#include "GameOfLife.h"
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: GOLApp <filename> [generations] [print interval]\n";
        return 1;
    }

    std::string filename = argv[1];
    int generations = 10;
    int printInterval = 1;

    if (argc >= 3) generations = std::atoi(argv[2]);
    if (argc >= 4) printInterval = std::atoi(argv[3]);

    try {
        gol::ParseResult parsed = gol::parseFile(filename);

        GameOfLife game(parsed.width, parsed.height, parsed.grid1D);

        game.printGame(); // Gen 0

        for (int i = 1; i <= generations; ++i) {
            game.next();
            if (i % printInterval == 0) {
                game.printGame();
            }
        }
    } catch (const gol::ParserError& e) {
        std::cerr << "Error parsing file: " << e.what() << '\n';
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
