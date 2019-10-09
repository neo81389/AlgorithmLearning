//
//  main.cpp
//  DijkstraAlgorithm
//
//  Created by Joonhee Lee on 2019/09/26.
//  Copyright © 2019 Joonhee Lee. All rights reserved.
//

#include <stdio.h>

#define l 9999
#define m 6

int dist[m] = {0,l,l,l,l,l};
int visit[m] = {0,0,0,0,0,0};
int v, i, s, p = 0;

//인접행렬
int graph[m][m] = {
//        A B C D E F
/*A*/    {0,7,9,4,l,l},
/*B*/    {l,0,1,2,l,l},
/*C*/    {l,l,0,5,7,9},
/*D*/    {l,2,l,0,8,3},
/*E*/    {l,l,l,8,0,8},
/*F*/    {l,l,9,l,l,0}
};
//Starting poing is A

void FindShortest(){
    
    s = l;
    
    for(i = 0; i < m; i++){
        if(dist[i] < s && visit[i] == 0) {
            s = dist[i];
            p = i;
        }// p is point which has shortest distance from A
    }

}

void dijkstra(){
    
    while(v < 6){
        
        for(i = 0; i < m; i++){ // X축
            if(dist[i] > dist[p] + graph[p][i]) dist[i] = dist[p] + graph[p][i];
        }
        
        visit[p] = 1;
        v++;
        
        FindShortest();
    }
}

int main() {
    
    dijkstra();
    
    for(i = 0; i < m; i++){
        printf("%d\n", dist[i]);
    }
    return 0;
}
