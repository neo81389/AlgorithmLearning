//
//  main.c
//  BOJ_10989번
//
//  Created by Joonhee Lee on 10/08/2019.
//  Copyright © 2019 Joonhee Lee. All rights reserved.
//
#include <stdio.h>
int a, i, left, right, pv;
int arr[1000010];

int pivot(int l, int r){
    return (l + r) / 2;
}

void quick(int p, int l, int r){
    
    pv = p;
    p = arr[p];
    
    int qleft = l;
    int qright = r;
    
    while(l <= r){
        
        if(arr[l] < p) l++;
        
        if(arr[r] > p) r--;
        
        if(arr[l] >= p && arr[r] <= p){
            int b = arr[r];
            arr[r] = arr[l];
            arr[l] = b;
            
            l++;
            r--;
        }
        
        if(r == pv) pv = l;
        if(l == pv) pv = r;
    }
    
    if(pv - qleft > 1) quick(pivot(qleft , pv - 1), qleft, pv - 1);
    
    if(qright - pv > 1) quick(pivot(pv + 1, qright), pv + 1, qright);
    
}

int main() {
    scanf("%d", &a);
    
    for(i = 0; i < a; i++) scanf("%d", &arr[i]);
    left = 0; right = a - 1;
    
    quick(pivot(left, right), left, right);
    
    for(i = 0; i < a; i++) printf("%d\n", arr[i]);
    
    return 0;
}
