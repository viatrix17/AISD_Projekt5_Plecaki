#include <iostream>
#include <fstream>

#include "../include/bruteForceMethod.h"
#include "../include/dynamicMethod.h"
#include "../include/generate.h"
#include "../include/read_backpack.h"
#include "../include/object_struct.h"

int main(){
    // ########  CZĘŚĆ PIERWSZA  ########
    std::cout << "\n----------------------------------------------------------\n\nPrezentujemy wczytywanie plecaka z pliku backpack.txt\noraz rozwiązanie na nim problemu plecakowego metodą brute force i dynamiczną:\n\n";
    int N, C; //ilosc przedmiotow, pojemnosc plecaka

    object *backpack = nullptr;
    read_backpack(backpack, N, C);

    if (backpack != nullptr) {
        std::cout << "backpack pobrany z pliku\n";
        for (int i = 0; i < N; ++i) {
        std::cout << "item " << i + 1 << ":\tp = " << backpack[i].p << ",\tw = " << backpack[i].w << '\n';
        }
        bruteForceMethod(backpack,N,C);
        dynamicMethod(backpack,N,C);
    }

    // ########  CZĘŚĆ DRUGA  ########
    std::cout << "\n----------------------------------------------------------\n\nGenerowanie plecaka, wypisanie go do pliku backpack.txt\noraz rozwiązanie na nim problemu plecakowego metodą brute force i dynamiczną:\n\n";
    std::cout << "\n\n[main]\t\twczytywanie N i C...\n";
    std::cin >> N >> C;
    backpack = new object[N];
    generate(backpack, N, C);
    std::cout << "\n\n";

    // Wypisywanie backpacka
    std::cout << "backpack wygenerowany według wczytanych danych\nN = " << N << "\nC = " << C << "\n";
    for (int i = 0; i < N; ++i) {
        std::cout << "item " << i + 1 << ":\tp = " << backpack[i].p << ",\tw = " << backpack[i].w << '\n';
    }
    std::cout << "\n";

    bruteForceMethod(backpack,N,C);
    dynamicMethod(backpack,N,C);

    delete[] backpack;
    return 0;
}



    // backpack[0].w = 8; backpack[0].p = 4;
    // backpack[1].w = 6; backpack[1].p = 3;
    // backpack[2].w = 2; backpack[2].p = 6;
    // backpack[3].w = 2; backpack[3].p = 9;