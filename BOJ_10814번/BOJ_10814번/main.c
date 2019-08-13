//
//  main.c
//  BOJ_10814번
//
//  Created by Joonhee Lee on 13/08/2019.
//  Copyright © 2019 Joonhee Lee. All rights reserved.
//

#include <stdio.h>

struct info{
    int age;
    char name[120];
    int order;
};

int a, i, left, right, pv, qleft, qright;
struct info info[100020];

int pivot(int l, int r){
    return (l + r) / 2;
}

void change(int l, int r){
    int b = info[l].age;
    info[l].age = info[r].age;
    info[r].age = b;
    
    b = info[l].order;
    info[l].order = info[r].order;
    info[r].order = b;
    
    char d[120];
    
    for(i = 0; i < sizeof(info[l].name); i++){
        d[i] = info[l].name[i];
    }
    
    char d[]
    info[l].name = info[r].name;
    info[r].name = b;
}

void quick(int p, int l, int r){
    pv = p;
    p = info[p].age;
    
    qleft = l;
    qright = r;
    
    while(l <= r){
        
        if(info[l].age < p) l++;
        if(info[r].age > p) r--;
        
        if(info[l].age >= p && info[r].age <= p){
            change(l, r);
            
            l++;
            r--;
            
            if(pv == l) pv = r;
            if(pv == r) pv = l;
        }
    }
    
    if(pv - qleft > 1) quick(pivot(qleft, pv - 1), qleft, pv - 1);
    if(qright - pv > 1) quick(pivot(pv + 1, qright), pv + 1, qright);
}

void quickorder(int p, int l, int r){
    pv = p;
    p = info[p].order;
    
    qleft = l;
    qright = r;
    
    while(l <= r){
        
        if(info[l].order < p) l++;
        if(info[r].order > p) r--;
        
        if(info[l].order >= p && info[r].order <= p){
            change(l, r);
            
            l++;
            r--;
            
            if(pv == l) pv = r;
            if(pv == r) pv = l;
        }
    }
    
    if(pv - qleft > 1) quick(pivot(qleft, pv - 1), qleft, pv - 1);
    if(qright - pv > 1) quick(pivot(pv + 1, qright), pv + 1, qright);
}

void order(){
    
    int t = info[0].order;
    int count = 0;
    for(i = 0; i < a; i++){
        if(info[i].order == t) count++;
        
        else{
            
            quickorder(pivot((i - 1) - (count - 1), i - 1), (i - 1) - (count - 1), i - 1);
            
            t = info[i].order;
            count = 0;
        }
    }
}

int main() {
    
    scanf("%d", &a);

    for(i = 0; i < a; i++){
        scanf("%d", &info[i].age);
        gets(info[i].name);
        info[i].order = i;
    }
    
    left = 0;
    right  = a - 1;
    
    quick(pivot(left, right), left, right);
    
    
    for(i = 0; i < a; i++){
        printf("%d ", info[i].age);
        printf("%s\n", info[i].name);
    }
    
    
    printf("\n");
    
    order();
    
    for(i = 0; i < a; i++){
        printf("%d ", info[i].age);
        printf("%s\n", info[i].name);
    }
    
    return 0;
}
