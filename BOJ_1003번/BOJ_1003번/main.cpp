//
//  main.cpp
//  BOJ_1003번
//
//  Created by Joonhee Lee on 13/08/2019.
//  Copyright © 2019 Joonhee Lee. All rights reserved.
//

#include <stdio.h>

int a, i;
int l, r = 0;
int mem[45];

int fibonacci(int n) {
    
    int result = n;
    
    if (n == 0) return l++;
    else if (n == 1) return r++;
    
    else {
        int b, c;
        if(mem[n - 1] != -1) b = mem[n - 1];
        
        if(mem[n - 2] != -1) c = mem[n - 2];
        mem[result] = fibonacci(n - 1) + fibonacci(n - 2);
        
        return fibonacci(mem[result]);
    }
}

int main() {

    scanf("%d", &a);
    
    for(i = 0; i < a; i++) {
        l = 0;
        r = 0;
        
        int t;
        scanf("%d", &t);
        fibonacci(t);
        
        printf("%d %d\n", l, r);
    }
    
    return 0;
}
