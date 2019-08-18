//
//  main.cpp
//  BOJ_1904번
//
//  Created by Joonhee Lee on 14/08/2019.
//  Copyright © 2019 Joonhee Lee. All rights reserved.
//
#include <stdio.h>
#include <iostream>

int a, i, t;
int result = 0;

int factorial(int t){
    int a = 1;
    for(i = 1; i <= t; i++) a = a * i;
    return a;
}

int main() {
    
    scanf("%d", &a);
    
    for(t = 0; t <= a/2; t++) {
        result += (factorial(t + (a - 2 * t)) / factorial(t) / factorial(a - 2 * t));
    }
    
    printf("%d", result);
   
    return 0;
}
