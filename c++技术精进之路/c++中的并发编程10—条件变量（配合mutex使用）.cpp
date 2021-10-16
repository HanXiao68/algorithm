////
////  c++中的并发编程9—条件变量（配合mutex使用）.cpp
////  程序喵
////
////  Created by 韩霄 on 2021/10/15.
//// 与9的区别主要是： 类Account中的changeMoney().写成了wait（）、motify()的条件变量锁。
////请注意：wait和notify_all虽然是写在一个函数中的，但是在运行时它们是在多线程环境中执行的，因此对于这段代码，需要能够从不同线程的角度去思考代码的逻辑。这也是开发并发系统比较难的地方。
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
//        unique_lock<mutex> lock(mu_money_lock);
////        lamda表达式
//        m_conditionVAR.wait(lock,[this,amount]{
//            return m_money + amount >0;
//        });
//
//        m_money +=amount;
//        m_conditionVAR.notify_all();
//    }
//    string get_name(){
//        return m_name;
//    }
//    double get_money(){
//        return m_money;
//    }
//
//private:
//    string m_name;
//    double m_money;
//    mutex mu_money_lock;
//    condition_variable m_conditionVAR;
//};
//
//class Bank{
//public:
//    void addBank(Account* account){
//        m_Accounts.insert(account);
//    }
////    重要的是这个方法，需要使用多线程+mutex互斥锁来实现线程间的同步。
//    void transferMoney(Account* accountA,Account* accountB,double amount){
////        C++11的标准库中提供了std::lock_guard类模板做mutex的RAII。
//
//
//        accountA->change_money(--amount);
//        accountB->change_money(amount);
//
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
//mutex sCountLock;
//void randomTransfer(Bank* bank,Account* accountA,Account* accountB){
//    while(true){
//        double randomMoney = ((double)rand() /RAND_MAX) * 100;
//        {
//            lock_guard<mutex> guard(sCountLock);
//            cout<<"转了"<<randomMoney<<"from"<<accountA->get_name()<<"到"<<accountB->get_name()<<",转的钱数是"<<randomMoney<<endl;
//
//        }
//        bank->transferMoney(accountA, accountB, randomMoney);
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
