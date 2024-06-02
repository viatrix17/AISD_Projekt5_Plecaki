#include <iostream>
#include <fstream>

#include "../include/bruteForceMethod.h"
#include "../include/dynamicMethod.h"
#include "../include/generate.h"
#include "../include/read_backpack.h"
#include "../include/object_struct.h"

int main(){
    std::string items[] = {"Cursed Sword", "Boots of Resistance", "Hellish Eye", "Diamond Armor", "Mirror of Truth", "Siren's Allure", "Dragon Tooth", "Fairy Wing", "Arcane Essence", "Skyward Blade", "Pearl of Wisdom", "Ubiquity Net", "Gold Pendant", "Almighty Hammer", "Tiara of Love", "Holy Grimoire"};
    // ########  CZĘŚĆ PIERWSZA  ########
    std::cout << "\n----------------------------------------------------------\n\nPrezentujemy wczytywanie plecaka z pliku backpack.txt\noraz rozwiązanie na nim problemu plecakowego metodą brute force i dynamiczną:\n\n";
    int N, C; //ilosc przedmiotow, pojemnosc plecaka

    object *knapsack = nullptr;
    read_backpack(knapsack, N, C);

    if (knapsack != nullptr) {
        std::cout << "Bottmless Bag loaded from a file:\n";
        for (int i = 0; i < N; ++i) {
        std::cout << i+1 << ". " << items[rand()%16] << ":\tp = " << knapsack[i].p << ",\tw = " << knapsack[i].w << '\n';
        }
        bruteForceMethod(knapsack,N,C);
        dynamicMethod(knapsack,N,C);
    }

    // ########  CZĘŚĆ DRUGA  ########
    std::cout << "\n----------------------------------------------------------\n\nGenerowanie plecaka, wypisanie go do pliku backpack.txt\noraz rozwiązanie na nim problemu plecakowego metodą brute force i dynamiczną:\n\n";
    std::cout << "\n\n[main]\t\twczytywanie N i C...\n";
    std::cin >> N >> C;
    knapsack = new object[N];
    generate(knapsack, N, C);
    std::cout << "\n\n";

    // Printing the knapsack
    std::cout << "Bottomless Bag (knapsack) generated based on loaded data\nN = " << N << "\nC = " << C << "\n";
    for (int i = 0; i < N; ++i) {
        std::cout << i+1 << ". " << items[rand()%16] << ":\tp = " << knapsack[i].p << ",\tw = " << knapsack[i].w << '\n';
    }
    std::cout << "\n";

    bruteForceMethod(knapsack,N,C);
    dynamicMethod(knapsack,N,C);

    delete[] knapsack;
    return 0;
}