#include <iostream>
#include <fstream>

#include "../include/object_struct.h"

void read_backpack(object *&backpack, int &N, int &C) {
    std::ifstream infile("backpack.txt");
    if (!infile) {
        std::cerr << "Błąd otwarcia pliku\n" << std::endl;
        return;
    }

    infile >> C >> N;

    backpack = new object[N];

    for (int i = 0; i < N; ++i) {
        infile >> backpack[i].p >> backpack[i].w;
    }

    infile.close();
}