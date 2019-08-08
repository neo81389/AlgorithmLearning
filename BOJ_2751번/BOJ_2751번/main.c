//
//  main.c
//  BOJ_2751번
//
//  Created by Joonhee Lee on 07/08/2019.
//  Copyright © 2019 Joonhee Lee. All rights reserved.
//

#include <stdio.h>

int a, i;
int l, r = 0;
int arr[10000];
int sorted[10000];

void merge(int list[], int left, int mid, int right){
    int i, j, k, l;
    i = left;
    j = mid+1;
    k = left;
    
    /* 분할 정렬된 list의 합병 */
    while(i<=mid && j<=right){
        if(list[i]<=list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    
    // 남아 있는 값들을 일괄 복사
    if(i>mid){
        for(l=j; l<=right; l++)
            sorted[k++] = list[l];
    }
    // 남아 있는 값들을 일괄 복사
    else{
        for(l=i; l<=mid; l++)
            sorted[k++] = list[l];
    }
    
    // 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
    for(l=left; l<=right; l++){
        list[l] = sorted[l];
    }
}

void sort(int list[], int left, int right){
    
    if(left < right){
        int mid = (l + r) / 2;
        sort(arr, l, mid);
        sort(arr, mid + 1, a - 1);
        
        merge(arr, left, mid, right);
    }
        
}

int main() {
    
    scanf("%d", &a);
    for(i = 0; i < a; i++) scanf("%d", &arr[i]);
    
    for(i = 0; i < a; i++){
        printf("%d\n", arr[i]);
    }
    
    return 0;
}
