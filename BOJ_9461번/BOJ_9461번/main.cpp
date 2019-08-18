//
//  main.cpp
//  BOJ_9461번
//
//  Created by Joonhee Lee on 16/08/2019.
//  Copyright © 2019 Joonhee Lee. All rights reserved.
//

#include <iostream>

int init[2147483647];
int arr[110];
int a, i;

void waveban(int a){
    
    int r = 5;
    
    if(a <= 5) printf("%d", init[arr[a - 1]]);
    
    else{
        
        int b = 0;
        b = (init[0] + init[4]);
        init[r] = b;
        r++;
        
        for(int t = 6; t < a; t++){
            b += init[t - 5];
            init[r] = b;
            r++;
        }
        
        printf("%d\n", b);
    }
}

int main() {
    
    init[0] = 1;
    init[1] = 1;
    init[2] = 1;
    init[3] = 2;
    init[4] = 2;
    
    scanf("%d", &a);
    for(i = 0; i < a; i++) scanf("%d", &arr[i]);
    
    for(i = 0; i < a; i++) waveban(arr[i]);
    
    return 0;
}
