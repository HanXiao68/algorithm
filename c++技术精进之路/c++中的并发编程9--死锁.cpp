////
////  c++中的并发编程--死锁.cpp
////  程序喵
////
////  Created by 韩霄 on 2021/10/15.
////
////死锁是并发编程中经常出现的一种问题。
////A B双方都有资源。且都在锁里。想要解锁，双方需要对方的资源。因此一直等待。
//
//#include <stdio.h>
//#include <iostream>
//#include <thread>
//#include <cmath>
//#include <string>
//#include <mutex>
//#include <set>
//
//using namespace std;
//
//class Account{
//
//public:
//    Account(string name,double money): m_name(name),m_money(money){};
//    void change_money(int amount){
//        m_money +=amount;
//    }
//    string get_name(){
//        return m_name;
//    }
//    double get_money(){
//        return m_money;
//    }
//    mutex* getLock(){
//        return &mu_money_lock;
//    }
//private:
//    string m_name;
//    double m_money;
//    mutex mu_money_lock;
//};
//
//class Bank{
//public:
//    void addBank(Account* account){
//        m_Accounts.insert(account);
//    }
////    重要的是这个方法，需要使用多线程+mutex互斥锁来实现线程间的同步。
//    bool transferMoney(Account* accountA,Account* accountB,double amount){
////        C++11的标准库中提供了std::lock_guard类模板做mutex的RAII。
//        lock_guard<mutex> guardA(*accountA->getLock());
//        lock_guard<mutex> guardB(*accountB->getLock());
//
//        if(amount > accountA->get_money()) return false;
//
//        accountA->change_money(--amount);
//        accountB->change_money(amount);
//        return true;
//    }
//    double totalMoney() const {
//        double sum =0;
//        for(auto a:m_Accounts) sum +=a->get_money();
//
//        return sum;
//    }
//
//private:
//    set<Account*> m_Accounts;
//};
//
//
////随即转钱，造成死锁的方法。
//void randomTransfer(Bank* bank,Account* accountA,Account* accountB){
//    while(true){
//        double randomMoney = ((double)rand() /RAND_MAX) * 100;
//        if(bank->transferMoney(accountA, accountB, randomMoney))
//            cout<<"转了"<<randomMoney<<"from"<<accountA->get_name()<<"到"<<accountB->get_name()<<",转的钱数是"<<randomMoney<<endl;
//        else
//            cout<<"转钱失败: 从"<<accountA->get_name()<<"到"<<accountB->get_name()<<endl;
//
//    }
//}
//
//int main(){
//    Account a("hanxiao",10000);
//    Account b("zhangsan",100);
//
//    Bank bank;
//    bank.addBank(&a);
//    bank.addBank(&b);
//
////    创建两个线程，在两个账户之间随机转钱。
//    thread t1(randomTransfer,&bank,&a,&b);
//    thread t2(randomTransfer,&bank,&a,&b);
//
//    t1.join();
//    t2.join();
//
//
//    return 0;
//}
