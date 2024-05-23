#include <iostream>
#include <math.h>

#include "../include/object_struct.h"

int suma_wag(object *backpack, int X)
{
    int suma = 0;
    int i = 0;
    while (X > 0)
    {
        suma += (X % 2) * backpack[i].w;
        X /= 2;
        i++;
    }
    return suma;
}

int suma_wartosci(object *backpack, int X)
{
    int suma = 0;
    int i = 0;
    while (X > 0)
    {
        suma += (X % 2) * backpack[i].p;
        X /= 2;
        i++;
    }
    return suma;
}

void bruteForceMethod(object *backpack, int N, int C) {
    int fmax = 0, rozwiazanie;
    for (int X = 1; X < pow(2, N); X++)
    {
        if (suma_wag(backpack, X) <= C){
            if (suma_wartosci(backpack, X) > fmax){
                fmax = suma_wartosci(backpack, X);
                rozwiazanie = X;
            }
        }
    }

    std::cout << "Max value of backpack: " << fmax << "\nPacked elements: ";
    int i = 0;
    while (rozwiazanie > 0)
    {
        if(rozwiazanie % 2){
            std::cout << i+1 << " ";
        }
        rozwiazanie /= 2;
        i++;
    }
    std::cout << "\n";
}