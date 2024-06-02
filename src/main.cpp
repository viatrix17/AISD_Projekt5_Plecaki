#include "../include/bruteForceMethod.h"
#include "../include/dynamicMethod.h"
#include "../include/generateKnapsack.h"
#include "../include/readKnapsack.h"
#include "../include/define_include.h"

void ifCorrectArgs(int argc, char *argv[], std::string &type) {
    if (argc <= 1) {
        std::cout << "No arguments given.\n";
        exit(0);
    }
    type = std::string(argv[1]);

    if (type != "--generate" && type != "--file-input") {
        std::cout << "Wrong arguments\n";
        exit(0);
    }
}

void printKnapsack(object *knapsack, int N){
    std::string items[] = {"Cursed Sword", "Boots of Resistance", "Hellish Eye", "Diamond Armor", "Mirror of Truth", "Siren's Allure", "Dragon Tooth", "Fairy Wing", "Arcane Essence", "Skyward Blade", "Pearl of Wisdom", "Ubiquity Net", "Gold Pendant", "Almighty Hammer", "Tiara of Love", "Holy Grimoire"};
    std::cout << "Contents of the Bottomless Bag:\n";
    for (int i = 0; i < N; ++i) {
        std::cout << i+1 << ". " << items[rand()%16] << ":\tp = " << knapsack[i].p << ",\tw = " << knapsack[i].w << '\n';
    }
}

int main(int argc, char *argv[]){

    std::string inputSource;
    ifCorrectArgs(argc, argv, inputSource);

    // ########  CZĘŚĆ PIERWSZA  ########
    std::cout << "\n----------------------------------------------------------\n\nKnapsack problem solved with brute force method and dynamic algorithm.\n\n";
    int N, C; //ilosc przedmiotow, pojemnosc plecaka

    object *knapsack = nullptr;
    if (inputSource == "--file-input") {
        readKnapsack(knapsack, N, C);
    }
    else if(inputSource == "--generate") {
        generateKnapsack(knapsack, N, C);
        
    }
    if (knapsack != nullptr) {
        printKnapsack(knapsack, N);
        bruteForceMethod(knapsack,N,C);
        dynamicMethod(knapsack,N,C);
    }

    std::cout << "\n----------------------------------------------------------\n";
    delete[] knapsack;
    return 0;
}