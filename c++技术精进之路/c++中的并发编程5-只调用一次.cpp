//
//  c++中的并发编程5.cpp
//  程序喵
//
//  Created by 韩霄 on 2021/10/15.
//有些任务，只希望他执行一次，例如资源的初始化。即使在多线程的环境下，我们也希望他只被调用一次。

#include <stdio.h>
#include <iostream>
#include <thread>
using namespace std;

void init(){
    cout<<"初始化线程。。。"<<endl;
//    下面可以写一些要做的逻辑
    
}
void worker(once_flag* flag){
    call_once(*flag,init);
}

//int main(){
//    once_flag flag;//属于mutex中的变量。
//    
//    thread t1(worker,&flag);
//    thread t2(worker,&flag);
//    thread t3(worker,&flag);
//    
//    t1.join();
//    t2.join();
//    t3.join();
//    
//    return 0;
//}



