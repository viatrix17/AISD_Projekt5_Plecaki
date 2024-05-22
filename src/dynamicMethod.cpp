#include <iostream>

#include "../include/object_struct.h"

void dynamicMethod(object *backpack, int N, int C){

    // object backpack[4];
    // int C = 8;
    // backpack[0].w = 2; backpack[0].p = 4;
    // backpack[1].w = 1; backpack[1].p = 3;
    // backpack[2].w = 4; backpack[2].p = 6;
    // backpack[3].w = 4; backpack[3].p = 8;
    int matrix[N+1][C+1];
    for(int i = 0; i < N+1; i++){
        for(int j = 0; j < C+1; j++) matrix[i][j] = 0;
    }
    int a;
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < C+1; j++){
            a = i-1;
            //std::cout << "a: " << a << " ";
            //std::cout << backpack[a].w << " " << backpack[a].p << "\n";
            if(backpack[a].w > j) matrix[i][j] = matrix[i-1][j]; //jak sie nie misci, to brac to co bylo o jedno wyzej
            else{ //jak sie miesci to wpakuj, jesli jest wieksze po dodaniu tego elementu
                matrix[i][j] = std::max(matrix[i-1][j], matrix[i-1][j-backpack[a].w] + backpack[a].p);
            }
        }   
    }

    std::cout << "Max value of backpack: " << matrix[N][C] << "\nPacked elements: ";
    int i = N, j = C;
    while(i > 0 && j > 0){
            if(matrix[i][j] != matrix[i-1][j]){
                std::cout << i << " ";
                i -= 1;
                j -= backpack[i-1].w;
            }
            else i -= 1;
    }
    std::cout << "\n";
}