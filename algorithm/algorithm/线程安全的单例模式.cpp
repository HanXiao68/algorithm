//
//  线程安全的单例模式.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/22.
//

#include <stdio.h>
#include <pthread.h>
#include <mutex>


using namespace std;

template <typename T>
class Singleton{
public:
//    双重锁 （一种方法）
    Singleton* getInstance(){
        if(value == nullptr)
        {
            m.lock();
            if(value ==nullptr)
                value = new Singleton();
        }
        m.unlock();
    }
    static T& instance (){
//        另一种方法：使用pthread_once(),参数1：pthread_once_t的实体。参数2：init函数
        pthread_once(&ponce, &Singleton::init);
    }
    static void init(){
        value = new T();
    }
private:
    Singleton();
    ~Singleton();
    static pthread_once_t ponce;
    static T* value = NULL;
    mutex m;
};
