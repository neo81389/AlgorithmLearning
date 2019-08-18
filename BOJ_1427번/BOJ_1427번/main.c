//
//  main.c
//  BOJ_1427번
//
//  Created by Joonhee Lee on 13/08/2019.
//  Copyright © 2019 Joonhee Lee. All rights reserved.
//

#include <stdio.h>

int a, i, t, b, c, m;
int state, count = 0;
int arr[10];

void bubble(){
    while(state != 1){
        
        count = 0;
        
        for(t = 0; t < i - 1; t++){
            if(arr[t] > arr[t + 1]){
                int d = arr[t];
                arr[t] = arr[t + 1];
                arr[t + 1] = d;}
            else count++;
        }
        if(count == i-1) state = 1;
    }
}

void toarray(){
    while(a >= 1){
        a = a / 10;
        i++;
    }

    for(t = i-1; t >= 0; t--){
        c = 1;
        for(b = 0; b < t; b++) c = c * 10;
        
        int buff = (m / c);
        m = m - c * buff;
        arr[a] = buff;
        a++;
    }
}

int main(){
    
    scanf("%d", &a);
    m = a;
    
    toarray();
    
    bubble();
    
    for(t = i-1; t >= 0; t--) printf("%d", arr[t]);
    
    return 0;
    
}
