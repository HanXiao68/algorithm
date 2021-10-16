////
////  c++中的并发编程8—竞争条件，互斥锁mutex.cpp
////  Created by 韩霄 on 2021/10/15.
////需要铺垫的知识：
//// 竞争条件：当多个进程或者线程同时访问共享数据时，只要有一个任务会修改数据，那么就会出现问题。最终的结果依赖于这些任务执行的顺序。以上就称为竞争条件。
////临界区：访问共享数据的代码片段就称为临界区。
////要想避免竞争条件，就需要对临界区进行数据保护。
//
////互斥体和锁 mutex
////多线程执行任务时，包含两种任务。1.执行分发给每个进程或线程的任务。2.汇总处理的结果。
////第一种任务不存在竞争条件。第二种任务存在竞争条件，需要使用锁来保证共享数据的访问是是互斥的。
////mutex就是实现了这样的功能。mutex是互斥的简写。
////主要的api有四个：1.lock（）上锁 2.unlock（）解锁。 3.加定时  4.try_to_lock()尝试加锁，在尝试未成功的时候，可能会失败
//
////优化锁：减小锁的粒度。锁的越少，临界区越小。性能越高，效率越快。
//#include <stdio.h>
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <cmath>
//#include <vector>
//using namespace std;
//
//static const int MAX = 1e8;
//static double sum =0;
//
//static mutex mu; //定义互斥锁变量为mu
//
//void concurrent_worker(int min,int max){
////    这里锁的粒度只锁住了sum+=sqrt(i);这句。优化点：原来是锁的for循环，后来锁一句，提高了性能。
//    for(int i=min;i<=max;i++){
//        mu.lock();
//        sum+=sqrt(i);
//        mu.unlock();
//    }
//}
//
//void concurrent_task(int min,int max){
//    auto start_time = chrono::steady_clock::now();
//    
//    unsigned concurrent_count = thread::hardware_concurrency();
//    cout<<"硬件的线程个数："<<concurrent_count<<endl;
//    vector<thread> threads;
//    min =0;
//    sum =0;
//    for(int t =0;t<concurrent_count;t++)
//    {
//        int range = max/concurrent_count;
//        threads.push_back(thread(concurrent_worker,0, range));
//        min = range+1;
//    }
////    启动所有的线程
//    for(int i=0;i<threads.size();i++){
//        threads[i].join();
//    }
//    
//    auto end_time = chrono::steady_clock::now();
//
//    
//    auto ms = chrono::duration_cast<chrono::milliseconds>(end_time-start_time).count();
//    cout<<"并发任务结束，花费了"<<ms<<"秒，最终结果是"<<sum<<endl;
//}
//
//int main(){
//    
//    concurrent_task(1,100);
//    
//    return 0;
//}
