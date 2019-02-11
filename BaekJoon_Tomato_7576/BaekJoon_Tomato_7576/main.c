//
//  main.c
//  토마토
//
//  Created by Joonhee Lee on 10/02/2019.
//  Copyright © 2019 Joonhee Lee. All rights reserved.
//

#include <stdio.h>

int map[1002][1002];
int bfs[1000002][3];

int x, y, i, t, a, b = 0;

int main() {
    
    printf("Hello, World!\n");
    
    scanf("%d %d", &x, &y);
    
    for(t = 0; t < y; t++)
        for(i = 0; i < x; i++){
            scanf("%d", &map[i][t]);
            if(map[i][t] == 1){
                bfs[a][0] = i;
                bfs[a][1] = t;
                bfs[a][2] = 0;
                a++;
            }
            if(map[i][t] == -1)
                b++;
        }
    
    if(b == x * y)
        b = -1;
    else
        b = 0;
    if(b == 0)
        for(t = 0; t < a; t++){
            
            if(bfs[t][2] > b)
                b++;
            
            if(bfs[t][0] + 1 < x && map[bfs[t][0] + 1][bfs[t][1]] == 0){
                map[bfs[t][0] + 1][bfs[t][1]] = 1;
                bfs[a][0] = bfs[t][0] + 1;
                bfs[a][1] = bfs[t][1];
                bfs[a][2] = bfs[t][2] + 1;
                a++;
            }
            
            if(bfs[t][0] - 1 >= 0 && map[bfs[t][0] - 1][bfs[t][1]] == 0){
                map[bfs[t][0] - 1][bfs[t][1]] = 1;
                bfs[a][0] = bfs[t][0] - 1;
                bfs[a][1] = bfs[t][1];
                bfs[a][2] = bfs[t][2] + 1;
                a++;
            }
            
            if(bfs[t][1] + 1 < y && map[bfs[t][0]][bfs[t][1] + 1] == 0){
                map[bfs[t][0]][bfs[t][1] + 1] = 1;
                bfs[a][0] = bfs[t][0];
                bfs[a][1] = bfs[t][1] + 1;
                bfs[a][2] = bfs[t][2] + 1;
                a++;
            }
            
            if(bfs[t][1] - 1 >= 0 && map[bfs[t][0]][bfs[t][1] - 1] == 0){
                map[bfs[t][0]][bfs[t][1] - 1] = 1;
                bfs[a][0] = bfs[t][0];
                bfs[a][1] = bfs[t][1] - 1;
                bfs[a][2] = bfs[t][2] + 1;
                a++;
            }
        }
    
    for(t = 0; t < y; t++)
        for(i = 0; i < x; i++)
            if(map[i][t] == 0)
                b = -1;
    
    printf("%d", b);
    return 0;
}
