//
//  c++中的并发编程7 单线程和并发任务2.cpp
//  程序喵
//
//  Created by 韩霄 on 2021/10/15.
//thread::hardware_concurrency()可以获取到当前硬件支持多少个线程并行执行。
//根据处理器的情况决定线程的数量。
//对于每一个线程都通过worker函数来完成任务，并划分一部分数据给它处理。
//等待每一个线程执行结束。

//这个方法不快，且是错误的。
//不快是因为需要线程之间的同步数据，而每个CPU中的数据需要从高速缓存cache需要同步到内存中。错误的是因为操作不是原子的。多线程可能读取到脏值，即中间值。
//#include <stdio.h>
//#include <iostream>
//#include <algorithm>
//#include <cmath>
//#include <thread>
//#include <vector>
//using namespace std;
//
//int sum;
//void worker(int min,int max){
//    for(int i=min;i<=max;i++){
//        sum += sqrt(i);
//    }
//}
//
//void concurrent_task(int min,int max){
//    auto start_time = chrono::steady_clock::now();
//
////    这个变量存放硬件中开启了多少个并行的线程个数。
//    unsigned concurrent_count = thread::hardware_concurrency();
//
//    vector<thread> threads;
//    min =0;
//    sum = 0;
//    for(int t =0;t<concurrent_count;t++){
//        int range = max / concurrent_count *(t-1);
//        threads.push_back(thread(worker,min,range));
//        min = range +1;
//    }
//    for(auto&t : threads) t.join(); //启动所有的线程。
//
//    auto end_time = chrono::steady_clock::now();
//    auto ms = chrono::duration_cast<chrono::milliseconds>(end_time-start_time).count();
//    cout<<"concurrent task finish, consumed"<< ms<<" ms consumed,\n Result: " << sum << endl;
//}
////int main(){
////
////    concurrent_task(0,100);
////    return 0;
////}
//
