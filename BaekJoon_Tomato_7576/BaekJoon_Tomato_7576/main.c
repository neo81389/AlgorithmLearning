//
//  main.c
//  untitled
//
//  Created by Joonhee Lee on 05/01/2019.
//  Copyright © 2019 Joonhee Lee. All rights reserved.
//

#include <stdio.h>
int x, y, m, n, a, t, b = 0;
int arr[1002][1002];
int bfs_x[1000002];
int bfs_y[1000002];

int main() {
    for(x = 0; x <= 1001; x++){
        for(y = 0; y <= 1002; y++)
            arr[x][y] = -1;
    }
    
    printf("start\n");
    
    //receiving primary information
    scanf("%d %d", &m, &n);
    
    for(x = 1; x <= m; x++){
        for(y = 1; y <= n; y++){
            scanf("%d", &arr[x][y]);
            if(arr[x][y] == -1)
                a--;
        }
    }
    
    //searching for ripen tomato
    printf("searching for ripen tomato\n");
    for(x = 1; x <= m; x++){
        for(y = 1; y <= n; y++){
            if(arr[x][y] == 1){
                bfs_x[a] = x;
                bfs_y[a] = y;
                a++;
            }
            
            if(arr[x][y] == 0){
                if(arr[x+1][y] == -1 && arr[x-1][y] == -1 && arr[x][y+1] == -1 && arr[x][y-1] == -1)
                    a = -1;
            }
            
            printf("%d ", a);
        }
        printf("\n");
    }
    
    printf("bfs start\n");
    if(a != -1 && a != -m * n){
        
        for(int t = 0; t < a; t++){
            
            for(y = 0; y < a; y++){
                printf("%d %d\n", bfs_x[y], bfs_y[y]);
            }
            printf("\n");
            
            if(arr[bfs_x[t] + 1][bfs_y[t]] == 0 && bfs_x[t] + 1 <= m){
                bfs_x[a] = bfs_x[t] + 1;
                bfs_y[a] = bfs_y[t];
                arr[bfs_x[t] + 1][bfs_y[t]] = 1;
                a++;
            }
            
            if(arr[bfs_x[t] - 1][bfs_y[t]] == 0 && bfs_x[t] - 1 >= 1){
                bfs_x[a] = bfs_x[t] - 1;
                bfs_y[a] = bfs_y[t];
                arr[bfs_x[t] + 1][bfs_y[t]] = 1;
                a++;
            }
            
            if(arr[bfs_x[t]][bfs_y[t] + 1] == 0 && bfs_y[t] + 1 <= n){
                bfs_x[a] = bfs_x[t];
                bfs_y[a] = bfs_y[t] + 1;
                arr[bfs_x[t] + 1][bfs_y[t]] = 1;
                a++;
            }
            
            if(arr[bfs_x[t]][bfs_y[t] - 1] == 0 && bfs_y[t] - 1 >= 1){
                bfs_x[a] = bfs_x[t];
                bfs_y[a] = bfs_y[t] - 1;
                arr[bfs_x[t] + 1][bfs_y[t]] = 1;
                a++;
            }
        }
    }
    
    printf("%d", a);
    
    return 0;
}
