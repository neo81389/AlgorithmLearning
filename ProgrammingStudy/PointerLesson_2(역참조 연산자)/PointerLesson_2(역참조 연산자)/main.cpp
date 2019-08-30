//
//  main.cpp
//  PointerLesson_2(역참조 연산자)
//
//  Created by Joonhee Lee on 31/08/2019.
//  Copyright © 2019 Joonhee Lee. All rights reserved.
//
// https://dojang.io/mod/page/view.php?id=276
// 포인터의 주소에 있는 값을 얻어오기위해 역참조 연산자를 활용한다.

#include <iostream>

int a = 1;
int *ptr = &a;

int main() {
 
    printf("%d\n", *ptr); //포인터 이름 앞에 "*"인 역참조 연산자를 붙이면 주소의 값을 가져온다.
    
    *ptr = 2;
    
    printf("%d\n", a); /*
                        포인터ptr이 a를 가르킨 상태(ptr에 a에 대한 주소가 저장된 상태)에서
                        a주소의 값을 역참조 연산자로 수정했다 */
    
    //TMI : &는 주소 연산자, *는 역참조 연산자
    
    
    /*
     "*"와 "&"는 자료형을 바꿔주는 역할을 한다
     포인터로 선언한 ptr은 pointer to int 라는 자료형이라 생각 하면된다. 겉 주소를 저장하는 연상자라 생각하자
     여기에 *ptr은 "pointer to"를 빼서 그냥 int 이다 해당 주소안에 있는 int라는 자료형이 된다.
     
     반대로 &는 int라는 자료형을 가진 변수의 주소를 접근하게 한다.
     address of int가 된다는 것이다.
     
     결국
     *ptr = a 가 성립되는것이고
     ptr = &a 가 성립되는것이다
     */
    
    return 0;
}
