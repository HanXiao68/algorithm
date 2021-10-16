//
//  c++中的并发编程4.cpp
//  程序喵
//
//  Created by 韩霄 on 2021/10/15.
//两种方法
//join（）：等地啊吸纳成完成其执行 和detach（） 允许线程独立执行。
//一旦启动线程之后，我们必须决定是要等待直接它结束（通过join），还是让它独立运行（通过detach），我们必须二者选其一。
//join：调用此接口时，当前线程会一直阻塞，直到目标线程执行完成（当然，很可能目标线程在此处调用之前就已经执行完成了，不过这不要紧）。因此，如果目标线程的任务非常耗时，你就要考虑好是否需要在主线程上等待它了，因此这很可能会导致主线程卡住。
//detach：detach是让目标线程成为守护线程（daemon threads）。一旦detach之后，目标线程将独立执行，即便其对应的thread对象销毁也不影响线程的执行。并且，你无法再与之通信
//如果在thread对象销毁的时候我们还没有做决定，则thread对象在析构函数出将调用std::terminate()从而导致我们的进程异常退出。

#include <stdio.h>
#include <iostream>
#include <thread>
#include <ctime>
#include <iomanip>
#include <sstream>

//创建了两个线程。它们都会有一些输出，其中一个会先停止3秒钟，然后再输出。主线程调用join会一直卡住等待它运行结束。
using namespace std;

void print_time(){
    auto now =chrono::system_clock::now();
    auto in_time_t = chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss<<put_time(localtime(&in_time_t),"%Y-%m-%d %X");
    cout<<"now is: "<<ss.str()<<endl;
}


void sleep_thread(){
    this_thread::sleep_for(chrono::seconds(3));
    cout<<"thread-"<<this_thread::get_id()<<"--- is waking up"<<endl;
}

void loop_thread(){
    for(int i=0;i<10;i++){
        cout<<" thread-"<<this_thread::get_id()<<"---print:"<<i<<endl;
    }
}

//使用两种方法创建线程。测试join()方法的阻塞
//int main(){
//    print_time();
////    创建线程直接用方法名，不要加括号。否则会报错!!
//    thread t1(sleep_thread);
//    thread t2(loop_thread);
//    
//    t1.join();
//    t2.detach();
//    print_time();
//    return 0;
//}
