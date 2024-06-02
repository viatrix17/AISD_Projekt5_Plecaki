#include "../include/define_include.h"

void generateKnapsack(object *&knapsack, int &N, int &C) {
    std::string line;
    int P;

    std::cout << "Enter N and C (in one line):\n";
    getline(std::cin, line);    
    ifCorrectInput(line);
    std::stringstream inputStream(line);
    inputStream >> N >> C;
    std::cout << "Enter the maximum value of the item:\n";
    getline(std::cin, line);    
    ifCorrectInput(line);
    std::stringstream inputStream2(line);
    inputStream2 >> P;

    knapsack = new object[N];
    
    std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<int> dist_weight(1, C + 1);
    std::uniform_int_distribution<int> dist_price(1, P);

    std::ofstream outfile("knapsack.txt", std::ios::out | std::ios::trunc);
    if (!outfile) {
        std::cout << "Error opening file.\n";
        exit(0);
    }

    outfile << C << '\n' << N << '\n';

    for (int i = 0; i < N; ++i) {
        knapsack[i].w = dist_weight(rng);
        knapsack[i].p = dist_price(rng);
        outfile << knapsack[i].p << ' ' << knapsack[i].w << '\n';
    }

    outfile.close();
    std::cout << "\nThe Bottomless Bag generated successfully\n\n";
}