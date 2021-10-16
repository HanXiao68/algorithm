// c++中的并发编程11--异步编程async.cpp
//  程序喵
//
//  Created by 韩霄 on 2021/10/15.
//

#include <stdio.h>
#include <future>
#include<iostream>
#include <cmath>

using namespace std;

static const int MAX = 1e8;
static double sum =0;

void worker(int min,int max){
    for(int i=min;i<=max;i++){
        sum +=sqrt(i);
    }
}

int main(){
    
    sum =0;
    auto f1 = async(worker,0,MAX);
    cout<<"异步任务触发"<<endl;
    f1.wait();
    cout<<"异步线程结束,sum的结果是："<< sum<<endl;
    
    return 0;
}


