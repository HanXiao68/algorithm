//
//  智能指针循环依赖问题.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/24.
//
#include <memory>

using namespace std;

template<class B>

class A{
public:
    shared_ptr<B> m_b;
};

template <typename A>
class B{
public:
    shared_ptr<A> m_a;
};

int main(){
    
    while(true){
//        新建的A和B对象的指针的个数是1
        shared_ptr<A> a(new A);
        shared_ptr<B> b(new B);
//        相互引用
        a->m_b = b;
        b->m_a = a;
    }
    
    return 0;
}

