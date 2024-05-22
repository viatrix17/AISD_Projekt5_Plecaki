#include <iostream>

#include "include/bruteForceMethod.h"
#include "include/dynamicMethod.h"
#include "include/generate.h"
#include "include/object_struct.h"

int main(){
    int N;
    std::cin >> N;
    object *backpack;
    backpack = new object[N];
    generate(backpack);
    bruteForceMethod(backpack);
    dynamicMethod(backpack);
    return 0;
}