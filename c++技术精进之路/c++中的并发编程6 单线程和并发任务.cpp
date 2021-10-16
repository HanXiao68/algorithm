////
////  c++中的并发编程6 单线程和并发任务.cpp
////  程序喵
////
////  Created by 韩霄 on 2021/10/15.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <thread>
//#include <algorithm>
//#include <cmath>//sqrt在这个头文件里。
//using namespace std;
//
//static const int MAX = 1e8;
//static double sum =0;
//
//void worker(int min,int max){
//    for(int i=min;i<=max;i++){
//        sum += sqrt(i);
//    }
//}
//
//void serial_task(int min,int max){
//    auto start_time = chrono::steady_clock::now();
//    sum =0;
//    worker(0,MAX);
//    auto end_time =chrono::steady_clock::now();
//    auto ms = chrono::duration_cast<chrono::milliseconds>(end_time-start_time).count();
//    cout << "Serail task finish, " << ms << " ms consumed,\n Result: " << sum << endl;
//}
//int main(){
//    
//    serial_task(0,100);
//    
//    return 0;
//}
