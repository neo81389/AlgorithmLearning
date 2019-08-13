//
//  main.c
//  BOJ_1427번
//
//  Created by Joonhee Lee on 13/08/2019.
//  Copyright © 2019 Joonhee Lee. All rights reserved.
//

#include <stdio.h>

int a, i, left, right, pv, buff, m;
int arr[10];
int d = 0;

int pivot(int l, int r){
    return (l + r) / 2;
}

void quick(int p, int l, int r){
    
    pv = p;
    p = arr[p];
    
    int qleft = l;
    int qright = r;
    
    while(l <= r){
        if(arr[l] > p) l++;
        if(arr[r] < p) r--;
        
        if(arr[l] <= p && arr[r] >= p){
            int b = arr[l];
            arr[l] = arr[r];
            arr[r] = b;
            
            l++;
            r--;
            
            if(pv == l) pv = r;
            if(pv == r) pv = l;
        }
    }
    
    if(pv - qleft > 1) quick(pivot(qleft, pv - 1), qleft, pv - 1);
    if(qright - pv > 1) quick(pivot(pv + 1, qright), pv + 1, qright);
    
}

int main() {
    scanf("%d", &m);
    
    buff = m;
    
    while(buff >= 10){
        buff = buff / 10;
        a++;
    }
    a++;
    
    for(i = a - 1; i >= 0; i--){
        
        int t = 1;
        
        for(int b = 0; b < i; b++) t = t * 10;
        
        int c = m / t;
    
        arr[d] = c;
        m = m - c * t;
        d++;
    }

    left = 0;
    right = a - 1;
    
    quick(pivot(left, right), left, right);
    
    for(i = 0; i < a; i++) printf("%d", arr[i]);
    return 0;
}
