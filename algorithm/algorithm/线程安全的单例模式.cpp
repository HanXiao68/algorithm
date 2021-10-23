//
//  线程安全的单例模式.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/22.
//

#include <stdio.h>
#include <pthread.h>



using namespace std;

template <typename T>
class Singleton{
public:
    static T& instance (){
        pthread_once(&ponce, &Singleton::init);
    }
    static void init(){
        value = new T();
    }
private:
    Singleton();
    ~Singleton();
    static pthread_once_t ponce;
    static T* value;
};
