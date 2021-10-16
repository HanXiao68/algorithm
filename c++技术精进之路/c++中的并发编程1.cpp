//
//  c++中的并发编程.cpp
//  程序喵
//
//  Created by 韩霄 on 2021/10/15.
//

#include <stdio.h>
#include <iostream>
#include <thread> //使用多线程时，需要用到这个库

using namespace std;

//为了使用多线程的接口，我们需要#include <thread>头文件。
//为了简化声明，本文中的代码都将using namespace std;。
//新建线程的入口是一个普通的函数，它并没有什么特别的地方。
//创建线程的方式就是构造一个thread对象，并指定入口函数。与普通对象不一样的是，此时编译器便会为我们创建一个新的操作系统线程，并在新的线程中执行我们的入口函数。
void hello(){
    
    cout<<"hello"<<endl;
}

//int main(){
//    thread t(hello);
//    t.join();
//
//
//    return 0;
//}

