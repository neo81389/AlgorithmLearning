//
//  main.cpp
//  BOJ_1149번
//
//  Created by Joonhee Lee on 16/08/2019.
//  Copyright © 2019 Joonhee Lee. All rights reserved.
//

#include <stdio.h>
int a, i;
int arr[1010][3];
int result[1010];
int count = 0;

int findlowest(int t){
    
    int b = arr[t][0];
    int buff = 0;
    
    for(int y = 0; y < 3; y++){
        if(arr[t][y] != -1){
            b = arr[t][y];
            buff = y;
            break;
        }
    }
    
    for(int y = 1; y < 3; y++){
        if(arr[t][y] < b && arr[t][y] != -1){
            b = arr[t][y];
            buff = y;
        }
    }
    
    return buff;
}

void save(){
    result[count] = arr[i][findlowest(i)];
    result[count++] = arr[i + 1][findlowest(i + 1)];
    count--;
}

int main() {
    
    scanf("%d", &a);
    for(i = 0; i < a; i++) {
        scanf("%d", &arr[i][0]);
        scanf("%d", &arr[i][1]);
        scanf("%d", &arr[i][2]);
    }
    
    for(i = 0; i < a - 1; i++){
        if(findlowest(i) == findlowest(i + 1)){
            if(findlowest(i) < findlowest(i + 1)) {
                arr[i + 1][findlowest(i + 1)] = -1;
                save();
            }
            if(findlowest(i) > findlowest(i + 1)) {
                arr[i][findlowest(i)] = -1;
                save();
            }
        }
        
        else save();
    }
    
    for(i = 0; i < count; i++) printf("%d\n", result[i]);
    
    return 0;
}
