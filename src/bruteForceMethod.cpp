#include <iostream>
#include <math.h>

#include "../include/object_struct.h"

int weight_sum(object *knapsack, int X) {
    int suma = 0, i = 0;
    while (X > 0) {
        suma += (X % 2) * knapsack[i].w;
        X /= 2;
        i++;
    }
    return suma;
}

int value_sum(object *knapsack, int X) {
    int suma = 0, i = 0;
    while (X > 0) {
        suma += (X % 2) * knapsack[i].p;
        X /= 2;
        i++;
    }
    return suma;
}

void bruteForceMethod(object *knapsack, int N, int C) {
    std::cout << "\nbruteForceMethod() :\n";

    int fmax = 0, result;
    for (int X = 1; X < pow(2, N); X++) {
        if (weight_sum(knapsack, X) <= C) {
            if (value_sum(knapsack, X) > fmax) {
                fmax = value_sum(knapsack, X);
                result = X;
            }
        }
    }

    std::cout << "Max value of Bottomless Bag: " << fmax << "\nPacked elements: ";
    int i = 0;
    while (result > 0) {
        if (result % 2) {
            std::cout << i+1 << " ";
        }
        result /= 2;
        i++;
    }
    std::cout << "\n";
}