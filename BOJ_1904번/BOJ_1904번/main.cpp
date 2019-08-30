//
//  main.cpp
//  BOJ_1904번
//
//  Created by Joonhee Lee on 14/08/2019.
//  Copyright © 2019 Joonhee Lee. All rights reserved.
//
#include <stdio.h>
#include <iostream>

int a, i, t, buff;
int result;

void cal(int t) {
    for(int i = 0; i < t; i++){
        buff = buff - 2;
    }
    result = buff;
}

int main() {
    
    scanf("%d", &a);
    
    for(t = 0; t <= a/2; t++){
        buff = a - 1;
        cal(t);
    }
    
    printf("%d", result);
   
    return 0;
}
