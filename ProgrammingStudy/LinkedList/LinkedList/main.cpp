//
//  main.cpp
//  CodeCity
//
//  Created by Joonhee Lee on 2019/10/02.
//  Copyright © 2019 Joonhee Lee. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode{
    element data;
    struct ListNode* link;
} ListNode;

void insert_node(ListNode** phead, ListNode* p, ListNode* new_node){
    
    if(*phead == NULL){
        new_node -> link = NULL;
        *phead = new_node;
    }
    
    else if(p == NULL){
        new_node -> link = *phead;
        *phead = new_node;
    }
    
    else{
        new_node -> link = p -> link;
        p -> link = new_node;
    }
}

void remove_node(ListNode **phead, ListNode *p, ListNode* removed){
    
    if(p == NULL) *phead = (*phead) -> link;
    /*
     '(*phead)' phead가 가르키는 것의 값을 말하는 것이다.
     앞서 remove_node에 **phead 에는 &list<숫자>, NULL, list<숫자>가 들어갔기 때문에
     결국 **phead에 list<숫자>의 주소값이 0X01이고, 그 값은 0X02를 가지고 있다고 한다면
     removed에 list<숫자>의 값인 0X02를 가지고 있기 때문에
     (*phead)의 값은 removed의 값과 동일하다.
     'removed -> link' 와 (*phead) -> link는 동일한 의미이다.
     */
    
    else p -> link = removed -> link;
    
    free(removed);
}

ListNode* concat(ListNode* head1, ListNode* head2){
    
    ListNode* p;
    if(head1 == NULL) return head2;
    
    else if (head2 == NULL) return head1;
    
    else{
        p = head1;
        while(p -> link != NULL) p= p -> link;
        
        p -> link = head2;
        return head1;
    }
}

void display(ListNode* head){
    
    ListNode* p = head;
    
    while(p != NULL){
        printf("%d ->", p ->data);
        p = p -> link;
    }
    
    printf("\n");
}

ListNode* search(ListNode* head, int x){
    ListNode* p;
    p = head;
    
    while(p != NULL){
        if(p -> data == x) return p;
        
        p = p -> link;
    }
    
    return p;
}

ListNode* reverse(ListNode* head){
    ListNode *p, *q, *r;
    p = head;
    q = NULL;
    
    while(p != NULL){
        r = q;
        q = p;
        p = p -> link;
        q -> link = r;
    }
    return q;
}


ListNode* create_node(element data, ListNode* link){
    ListNode* new_node;
    new_node = (ListNode*)malloc(sizeof(ListNode));
    /*
     sizeof()는 변수의 Byte값을 전달한다
     malloc()은 받은 Byte들 중 첫번째 Byte의 주솟 값을 반환한다 (이때 void pointer로 반환한다)
     '(자료형)'은 뒤에 오는 값의 자료형을 강제로 변환한다.
     */
    if(new_node == NULL) printf("메모리 할당 애러");
    new_node->data = data;
    new_node->link = link;
    return (new_node);
}

int main() {
    
    ListNode *list1 = NULL, *list2 = NULL;
    ListNode *p;

    insert_node(&list1, NULL,create_node(10, NULL));
    insert_node(&list1, NULL,create_node(20, NULL));
    insert_node(&list1, NULL,create_node(30, NULL));
    display(list1);
    
    remove_node(&list1, NULL, list1);
    display(list1);
    
    insert_node(&list2, NULL,create_node(60, NULL));
    insert_node(&list2, NULL,create_node(70, NULL));
    insert_node(&list2, NULL,create_node(80, NULL));
    display(list2);
    
    list1 = concat(list1, list2);
    display(list1);
    
    list1 = reverse(list1);
    display(list1);
    
    p = search(list1, 20);
    printf("탐색성공: %d\n", p->data);
    
    return 0;
}
