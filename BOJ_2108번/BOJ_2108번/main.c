//
//  main.c
//  BOJ_2108번
//
//  Created by Joonhee Lee on 13/08/2019.
//  Copyright © 2019 Joonhee Lee. All rights reserved.
//

#include <stdio.h>

int a, i, left, right, pv, count, min, max;
int arr[1000010];

int pivot(int l, int r){
    return (l + r) / 2;
}

int most(){
    int b = 0;
    int c = 0;
    pv = arr[0];//prev
    int most[1000010][2];
    int buff[1000010];
    most[0][0] = pv;
    most[0][1] = 1;
    
    for(i = 1; i < a; i++){
        if(most[b][0] == arr[i]){
            most[b][1]++;
        }
        else{
            b++;
            most[b][0] = arr[i];
            most[b][1] = 1;
        }
    }
    
    max = 0;
    for(i = 0; i <= b; i++){
        
        if(most[i][1] > max){
            count = 0;
            max = most[i][0];
        }
        
        if(most[i][1] == max){
            count++;
            buff[c] = most[i][0];
            c++;
        }
    }
    
    if(count == 1) b = max;
    else b = buff[1];
    
    return b;
}

void quick(int p, int l, int r){
    
    pv = p;
    p = arr[p];
    
    int qleft = l;
    int qright = r;
    
    while(l <= r){
        
        if(arr[l] < p) l++;
        if(arr[r] > p) r--;
        
        int b = arr[r];
        arr[r] = arr[l];
        arr[l] = b;
        
        l++;
        r--;
    }
    
    if(pv == l) pv = r;
    if(pv == r) pv = l;
    
    if(pv - qleft > 1) quick(pivot(qleft, pv - 1), qleft, pv - 1);
    if(qright - pv > 1) quick(pivot(pv + 1, qright), pv + 1, qright);
}

int main() {
    
    scanf("%d", &a);
    
    for(i = 0; i < a; i++) scanf("%d", &arr[i]);
    left = 0; right = a - 1;
    
    quick(pivot(left, right), left, right);
    
    pv = 0;
    
    printf("\n");
    
    for(i = 0; i < a; i++) pv += arr[i];
    printf("%d\n\n", pv / (a - 1));
    
    printf("%d\n\n", arr[pivot(left, right)]);
    
    printf("%d\n\n", most());
 
    return 0;
}
