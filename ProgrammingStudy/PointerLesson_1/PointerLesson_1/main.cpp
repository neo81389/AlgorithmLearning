//
//  main.cpp
//  PointerLesson_1
//
//  Created by Joonhee Lee on 31/08/2019.
//  Copyright © 2019 Joonhee Lee. All rights reserved.
//
// https://dojang.io/mod/page/view.php?id=274
// this lesson is at in coding dojang 34.0 and 34.1

#include <iostream>

int *ptr;

int main() {
    // insert code here...
    
    int a = 10;
    
    ptr = &a;
    
    printf("%p\n", &a);//서식 지정자 %p, 주소연산자 : &
    
    printf("%p", ptr);//포인터 = 메모리 주소
    
    return 0;
}
