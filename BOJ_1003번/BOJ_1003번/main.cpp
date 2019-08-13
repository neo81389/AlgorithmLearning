//
//  main.cpp
//  BOJ_1003번
//
//  Created by Joonhee Lee on 13/08/2019.
//  Copyright © 2019 Joonhee Lee. All rights reserved.
//

#include <stdio.h>

int a, i;
int arr[10000000];
int count[100000000][2];

int fibonacci(int n, int i){
    
    if(n == 0){
        count[i][0]++;
        return 0;
    }
    else if(n == 1){
        count[i][1]++;
        return 1;
    }
    else{
        return fibonacci(n - 1, i) + fibonacci(n - 2, i);
    }
}

int main() {

    scanf("%d", &a);
    for(i = 0; i < a; i++){
        scanf("%d", &arr[i]);
    }
    
    for(i = 0; i < a; i++){
        fibonacci(arr[i], i);
        printf("%d ", count[i][0]);
        printf("%d\n", count[i][1]);
    }
    
    return 0;
}
