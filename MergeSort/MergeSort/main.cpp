//
//  main.cpp
//  MergeSort
//
//  Created by Joonhee Lee on 2019/09/27.
//  Copyright © 2019 Joonhee Lee. All rights reserved.
//

#include <stdio.h>

#define M 8

int arr[M] = {1,3,10,2,7,9,1,5};

void Merge(int left, int mid, int right, int list[]){
    
    
    
}

void MergeSort(int left, int right, int list[]){
    
    if(left < right){
        int mid = (left + right) / 2;
        
        MergeSort(left, mid, list);
        MergeSort(mid + 1, right, list);
        
        Merge(left, mid, right, list);
    }
}

int main() {
    
    MergeSort(0, M-1, arr);
    
    return 0;
}
