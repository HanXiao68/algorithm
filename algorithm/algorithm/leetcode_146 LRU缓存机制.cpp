//
//  leetcode_146 LRU缓存机制.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/26.
//

#include <list>
#include <unordered_map>

using namespace std;

class LRUCache{
    
public:
    LRUCache(int cap): cap(cap),cur(0),ls(),hashmap(){}
    int get(int key){
        
        if(hashmap.find(key) == hashmap.end()) return -1;
            auto itr = hashmap[key];
            if(itr == ls.begin()) return ls.begin()->second;
//          链表头部插入
            ls.push_front(pair<int,int>(itr->first,itr->second));
//          拿到链表头部的迭代器，用来覆盖hashmap。 删除链表原来的迭代器。
            auto new_itr = ls.begin();
            ls.erase(itr);
            hashmap[key] = new_itr;
        return new_itr->second;
    }
    
    void put(int key,int value){
        if(hashmap.find(key) !=hashmap.end()){
            
            ls.erase(hashmap[key]);
            ls.push_front(pair<int,int>(key,value));
            hashmap[key] = ls.begin();
            return;
        }
//        没找到
        else{
            if(cur == cap){
                hashmap.erase(ls.back().first);
                ls.pop_back();
                cur--;
            }
            ls.push_front(pair<int,int>(key,value));
            auto new_itr = ls.begin();
            hashmap[key] = new_itr;
            cur++;
        }
    }
    
private:
    int cap;//容量
    int cur;//当前个数指针
    list<pair<int,int>> ls;
    unordered_map<int, list<pair<int,int>>::iterator> hashmap;
    
};
