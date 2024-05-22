#include <iostream>

#include "../include/bruteForceMethod.h"
#include "../include/dynamicMethod.h"
#include "../include/generate.h"
#include "../include/object_struct.h"

int main(){
    int N, C; //ilosc przedmiotow, pojemnosc plecaka
    std::cin >> N >> C;
    object *backpack;
    backpack = new object[N];
    //generate(backpack);
    bruteForceMethod(backpack);
    dynamicMethod(backpack,N,C);
    return 0;
}