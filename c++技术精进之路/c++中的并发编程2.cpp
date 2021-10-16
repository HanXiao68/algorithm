//
//  c++中的并发编程2.cpp
//  程序喵
//
//  Created by 韩霄 on 2021/10/15.
//

#include <stdio.h>
#include <iostream>
#include <thread>

//thread 可以和callable一起工作。因此，可以使用lamda表达式写线程的逻辑
//using namespace std;
//
//int main(){
//    
//    thread t([]{
//        cout<<"hello hanxiao, lamda"<<endl;
//    });
//    t.join();
//    
//    return 0;
//}
