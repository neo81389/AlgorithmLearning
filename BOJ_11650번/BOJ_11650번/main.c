//
//  main.c
//  BOJ_11650번
//
//  Created by Joonhee Lee on 13/08/2019.
//  Copyright © 2019 Joonhee Lee. All rights reserved.
//

// this programm also can be use for 11651번
#include <stdio.h>

int a, arr[1000000][2];

int partition(int left, int right, int pivot, int t) {
   int l = left -1;
   int r = right;

   while(1) {
      while(arr[++l][t] < pivot) {}
        
      while(r > 0 && arr[--r][t] > pivot) {}

      if(l >= r) break;
       
      else {
          int b = arr[l][0];
          arr[l][0] = arr[r][0];
          arr[r][0] = b;
          
          b = arr[l][1];
          arr[l][1] = arr[r][1];
          arr[r][1] = b;
      }
   }
    
    int b = arr[l][0];
    arr[l][0] = arr[right][0];
    arr[right][0] = b;
    
    b = arr[l][1];
    arr[l][1] = arr[right][1];
    arr[right][1] = b;
    
   return l;
}

void quick(int left, int right, int t) {
    
   if(right-left <= 0) return;

   else {
      int pivot = arr[right][t];
      int partitionPoint = partition(left, right, pivot, t);
      quick(left,partitionPoint-1, t);
      quick(partitionPoint+1,right, t);
   }
}

void sort_x(){
    int c = arr[0][1];
    int count = 0;
    for(int i = 0; i <= a; i++){
        if(arr[i][1] == c) count++;
        
        else{
            quick((i - 1) - (count - 1), i - 1 , 0);
            
            count = 1;
            c = arr[i][1];
        }
    }
}

int main() {
    
    scanf("%d", &a);
    
    for(int i = 0; i < a; i++){
        scanf("%d", &arr[i][0]);
        scanf("%d", &arr[i][1]);
    }
    
    quick(0,a - 1, 1);
    
    sort_x();
    
    for(int i = 0; i < a; i++) {
        printf("%d " ,arr[i][0]);
        printf("%d\n" ,arr[i][1]);
    }
    
    return 0;
}
