//
//  main.c
//  BaekJoon_Tomato_7576
//
//  Created by Joonhee Lee on 30/12/2018.
//  Copyright © 2018 Joonhee Lee. All rights reserved.
//
//problem I've solved is on https://www.acmicpc.net/problem/7578
//How I solved is described on https://blog.naver.com/robo813/221431533471
//
#include <stdio.h>

int m, n, x ,y, a = 0;
int arr[1002][1002];

void change(){
    a++;
    for(y = 1; y <= n; y++){
        for(x = 1; x <= m; x++){
            if(arr[x][y] == a){
                if(arr[x+1][y] == 0) arr[x+1][y] = a+1;
                
                if(arr[x-1][y] == 0) arr[x-1][y] = a+1;
                
                if(arr[x][y+1] == 0) arr[x][y+1] = a+1;
                
                if(arr[x][y-1] == 0) arr[x][y-1] = a+1;
            }
        }
    }
    
    for(y = 1; y <= n; y++){
        for(x = 1; x <= m; x++){
            if(arr[x][y] == 0) change();
        }
    }
}

int main(){
    
    for(y = 0; y <= 1001; y++){
        for(x = 0; x <= 1001; x++){
            arr[x][y] = -1;
        }
    }
    
    printf("%d", arr[1][1]);
    printf("start\n");
    scanf("%d %d", &m, &n); // 배열 크기 받기
    
    for(y = 1; y <= n; y++){
        for(x = 1; x <= m; x++){
            scanf("%d", &arr[x][y]); // 배열 정보 받기
            if(arr[x][y] == -1)
                a--;
        }
    }
    
    for(y = 1; y <= n; y++){
        for(x = 1; x <= m; x++){
            if(arr[x][y] == 0 && arr[x+1][y] == -1 && arr[x-1][y] == -1 && arr[x][y+1] == -1 && arr[x][y-1] == -1)
                a = -2;
        }
    }

    //배열 확인 하고 변화 해야할 토마토 있으면 시작
    for(y = 1; y <= n; y++){
        for(x = 1; x <= m; x++){
            if(arr[x][y] == 0 && a != -2 && a != -m * n) {
                a = 0;
                change();
                
            }
        }
    }
    //몇 일 거리는지 확인
    if(a > 0) printf("%d\n", a);
    else printf("-1\n");

    return 0;
}
