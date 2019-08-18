//
//  main.cpp
//  quickingAlgorithm
//
//  Created by Joonhee Lee on 14/08/2019.
//  Copyright © 2019 Joonhee Lee. All rights reserved.
//

#include <stdio.h>

int a, arr[10000];

int partition(int left, int right, int pivot) {
   int l = left -1;
   int r = right;

   while(1) {
      while(arr[++l] < pivot) {}
        
      while(r > 0 && arr[--r] > pivot) {}

      if(l >= r) break;
       
      else {
          int b = arr[l];
          arr[l] = arr[r];
          arr[r] = b;
      }
   }
    
    //pivot swap
    int b = arr[l];
    arr[l] = arr[right];
    arr[right] = b;
    
   return l;
}

void quick(int left, int right) {
    
   if(right-left <= 0) return;

   else {
      int pivot = arr[right];
      int partitionPoint = partition(left, right, pivot);
      quick(left,partitionPoint-1);
      quick(partitionPoint+1,right);
   }
}

int main() {
    
    scanf("%d", &a);
    for(int i = 0; i < a; i++) scanf("%d", &arr[i]);
    
    quick(0,a - 1);

    for(int i = 0; i < a; i++) printf("%d\n",arr[i]);
}
