//
//  main.cpp
//  PointerLearning_3(이중포인터)
//
//  Created by Joonhee Lee on 01/09/2019.
//  Copyright © 2019 Joonhee Lee. All rights reserved.
//

#include <iostream>

int *ptr1; // pointer to int
int **ptr2; // pointer to pointer to int 요런 느낌
int num = 10;

int main() {
    
    ptr1 = &num;
    
    //포인터도 일종의 변수
    //하지만! 포인터의 주소 값은 포인터가 아닌 이중 포인터만이 저장할 수 있다.
    //이중 뿐만 아니라 삼중, 사중, 그 이상도 만들 수 있다.
    ptr2 = &ptr1;
    
    printf("%d\n", **ptr2);
    
    return 0;
}
