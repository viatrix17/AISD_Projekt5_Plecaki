#include <iostream>
#include <math.h>
#include <random>
#include <ctime>
#include <fstream>

#include "../include/object_struct.h"

void generate(object *knapsack, int N, int C) {
    int P;
    std::cout << "[generate]\twczytywanie maksymalnej możliwej wartości przedmiotu...\n";
    std::cin >> P;

    std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<int> dist_weight(1, C + 1);
    std::uniform_int_distribution<int> dist_price(1, P);

    std::ofstream outfile("backpack.txt");
    if (!outfile) {
        std::cout << "Error opening file.\n";
        return;
    }

    outfile << C << '\n' << N << '\n';

    for (int i = 0; i < N; ++i) {
        knapsack[i].w = dist_weight(rng);
        knapsack[i].p = dist_price(rng);
        outfile << knapsack[i].p << ' ' << knapsack[i].w << '\n';
    }

    outfile.close();
}