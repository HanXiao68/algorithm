//
//  手写智能指针shareed_ptr.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/24.
//

#include <stdio.h>
template<typename  T>
class SharedPtr{
public:
    SharedPtr():_ptr((T*)0),_refCount(0){}
    SharedPtr(T *obj):_ptr(obj),_refCount(new int(1)){}
    SharedPtr(SharedPtr& other):_ptr(*other._ptr),_refCount(&(++ *other._refCount)){}
    ~SharedPtr(){
        if(_ptr && --*_refCount ==0){
            delete _ptr;
            _ptr =nullptr;
            delete _refCount;
            _refCount ==nullptr;
        }
    }
    
    SharedPtr &operator=(SharedPtr& other)
    {
        if(this == &other) return *this;
        ++*other._refCount;
        if(-- *_refCount == 0){
            delete _ptr;
            _ptr =nullptr;
            delete _refCount;
            _refCount = nullptr;
        }
        _ptr = other._ptr;
        _refCount = other._refCount;
    }
    T &operator*(){
        if(_refCount ==0) return (T*)0;
        return  _ptr;
    }
    
    T &operator->(){
        if(_refCount ==0) return nullptr;
        return _ptr;
    }
private:
    T* _ptr;
    int* _refCount;
};

