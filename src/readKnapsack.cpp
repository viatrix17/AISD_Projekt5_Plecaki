#include "../include/define_include.h"

void readKnapsack(object *&knapsack, int &N, int &C) {
    std::ifstream infile("knapsack.txt");
    if (!infile) {
        std::cerr << "Error opening the file. The file must be named 'knapsack.txt'\n" << std::endl;
        exit(0);
    }

    infile >> C >> N;

    knapsack = new object[N];

    for (int i = 0; i < N; ++i) {
        infile >> knapsack[i].p >> knapsack[i].w;
    }

    infile.close();
    std::cout << "The Bottomless Bag loaded from the file successfully.\n\n";
}