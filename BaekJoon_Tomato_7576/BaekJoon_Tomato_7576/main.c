//
//  main.c
//  BaekJoon_Tomato_7576
//
//  Created by Joonhee Lee on 30/12/2018.
//  Copyright © 2018 Joonhee Lee. All rights reserved.
//
#include <stdio.h>

int m, n = 0;
int x, y;
int a = 0;
int arr[1001][1001];

void change(){
    a++;
    for(y = 1; y <= n; y++){
        for(x = 1; x <= m; x++){
            if(arr[x][y] == 1){
                if(arr[x+1][y] == 0) arr[x+1][y] = 2;
                
                if(arr[x-1][y] == 0) arr[x-1][y] = 2;
                
                if(arr[x][y+1] == 0) arr[x][y+1] = 2;
                
                if(arr[x][y-1] == 0) arr[x][y-1] = 2;
            }
        }
    }
    
    for(y = 1; y <= n; y++){
        for(x = 1; x <= m; x++){
            if(arr[x][y] == 2) arr[x][y] = 1;
        }
    }
    
    for(y = 1; y <= n; y++){
        for(x = 1; x <= m; x++){
            if(arr[x][y] == 0 && a < 10000) change();
        }
    }
}

int main(){
    printf("start\n");
    scanf("%d %d", &m, &n); // 배열 크기 받기
    
    for(y = 1; y <= n; y++){
        for(x = 1; x <= m; x++){
            scanf("%d", &arr[x][y]); // 배열 정보 받기
        }
    }
    //배열 확인 하고 변화 해야할 토마토 있으면 시작
    for(y = 1; y <= n; y++){
        for(x = 1; x <= m; x++){
            if(arr[x][y] == 0) change();
        }
    }
    //몇 일 거리는지 확인
    if(a < 10000) printf("%d\n", a);
    else printf("-1\n");

    return 0;
}
