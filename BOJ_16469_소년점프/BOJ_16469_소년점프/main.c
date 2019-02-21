//
//  main.c
//  BOJ_16469_소년점프
//
//  Created by Joonhee Lee on 11/02/2019.
//  Copyright © 2019 Joonhee Lee. All rights reserved.
//

#include <stdio.h>

int x, y, i, t, a, b, c = 0;
int map[102][102];
int q[3][10002][2];
int main() {
    printf("Hello, World!\n");
    
    scanf("%d %d", &x, &y);
    
    for(t = 0; t < y; t++)
        for(i = 0; i < x; i++)
            scanf("%d", &map[i][t]);
    
    for(t = 0; t < 3; t++){
        scanf("%d %d", &q[t][a][0], &q[t][a][1]);
    }
    
    for(t = 0; t < a; t++){
        
    }
    
    return 0;
}
