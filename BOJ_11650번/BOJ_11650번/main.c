//
//  main.c
//  BOJ_11650번
//
//  Created by Joonhee Lee on 13/08/2019.
//  Copyright © 2019 Joonhee Lee. All rights reserved.
//
#include <stdio.h>

int a, i, left, right, pv;
int arr[100020][2];

int pivot(int l, int r){
    return (l + r) / 2;
}

void quick(int p, int l, int r, int s){
    pv = p;
    p = arr[p][s];
    
    int qleft = l;
    int qright = r;
    
    while(l <= r){
        if(arr[l][s] < p) l++;
        if(arr[r][s] > p) r--;
        
        if(arr[l][s] >= p && arr[r][s] <= p){
            int b = arr[l][s];
            arr[l][s] = arr[r][s];
            arr[r][s] = b;
            
            l++;
            r--;
            
            if(pv == l) pv = r;
            if(pv == r) pv = l;
        }
    }
    
    if(pv - qleft > 1) quick(pivot(qleft, pv - 1), qleft, pv - 1, s);
    if(qright - pv > 1) quick(pivot(pv + 1, qright), pv + 1, qright, s);
    
}

void sort(){
    int c = arr[0][0];
    int count = 0;
    for(i = 0; i < a; i++){
        
        if(arr[i][0] == c) count++;
        
        else{
            quick(pivot((i - 1) - (count - 1), i - 1), (i - 1) - (count - 1), i - 1, 1);
            
            count = 1;
            c = arr[i][0];
        }
    }
}

int main() {
    
    scanf("%d", &a);
    
    for(i = 0; i < a; i++){
        scanf("%d", &arr[i][0]);
        scanf("%d", &arr[i][1]);
    }
    printf("\n");
    
    left = 0;
    right = a - 1;
    
    quick(pivot(left, right), left, right, 0);
    
    sort();
    
    for(i = 0; i < a; i++) {
        printf("%d " ,arr[i][0]);
        printf("%d\n" ,arr[i][1]);
    }
    
    return 0;
}
