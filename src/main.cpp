#include <iostream>

#include "../include/bruteForceMethod.h"
#include "../include/dynamicMethod.h"
#include "../include/generate.h"
#include "../include/object_struct.h"

int main(){
    int N, C; //ilosc przedmiotow, pojemnosc plecaka
    // std::cin >> N >> C;
    // object *backpack;
    // backpack = new object[N];

    N = 4;
    object backpack[4];
    C = 8;
    backpack[0].w = 2; backpack[0].p = 4;
    backpack[1].w = 1; backpack[1].p = 3;
    backpack[2].w = 4; backpack[2].p = 6;
    backpack[3].w = 4; backpack[3].p = 8;

    std::cout << "\n---------------------------\n";
    //generate(backpack);
    bruteForceMethod(backpack,N,C);
    dynamicMethod(backpack,N,C);
    return 0;
}