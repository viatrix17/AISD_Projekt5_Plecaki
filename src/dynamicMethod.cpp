#include "../include/define_include.h"

void findResult(object *knapsack, int **costMatrix, int N, int C) {
    int a;
    for(int i = 1; i < N+1; i++) {
        for(int j = 1; j < C+1; j++) {
            a = i-1;
            if(knapsack[a].w > j) {
                costMatrix[i][j] = costMatrix[i-1][j];
            }
            else{
                costMatrix[i][j] = std::max(costMatrix[i-1][j], costMatrix[i-1][j-knapsack[a].w] + knapsack[a].p);
            }
        }   
    }
}

void displayResult(object *knapsack, int **costMatrix, int N, int C) {
    std::cout << "Max value of Bottomless Bag: " << costMatrix[N][C] << "\nPacked elements: ";
    int i = N, j = C;
    while(i > 0 && j > 0) {
            if(costMatrix[i][j] != costMatrix[i-1][j]) {
                std::cout << i << " ";
                j -= knapsack[i-1].w;
            }
            i -= 1;
    }
    std::cout << "\n";
}

void dynamicMethod(object *knapsack, int N, int C) {
    std::cout << "\nDynamic Method:\n";

    int **costMatrix;
    costMatrix = new int*[N+1];
    for(int i = 0; i < N+1; i++) {
        costMatrix[i] = new int[C+1];
    }

    for(int i = 0; i < N+1; i++) {
        for(int j = 0; j < C+1; j++) {
            costMatrix[i][j] = 0;
        }
    }

    findResult(knapsack, costMatrix, N, C);
    displayResult(knapsack, costMatrix, N, C);

    for (int i = 0; i < N+1; i++) {
        delete[] costMatrix[i];
    }
    delete[] costMatrix; 
}