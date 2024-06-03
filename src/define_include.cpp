#include "../include/define_include.h"

void ifCorrectInput(std::string line) {
    for (int j = 0; j < line.size(); j++) {
            if (line[j] != ' ') {
                if (!((line[j] >= '1' && line[j] <= '9') || line[j] == ' ')) {
                    std::cout << "Wrong type of data.\nExiting the program...\n";
                    exit(0);
                }
            }
        }
}