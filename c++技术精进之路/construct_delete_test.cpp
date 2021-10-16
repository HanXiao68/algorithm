//
//  main.cpp
//  程序喵
//当类型为int, float等内置类型时，new、delete、new[]、delete[]不需要配对使用；
//当是自定义类型时，new、delete和new[]、delete[]才需要配对使用。
//当然，我们平时编程过程中，为了保证代码的可读性，以及养成良好的编程习惯，最好确保所有情况都配对使用
//  Created by 韩霄 on 2021/10/1.
//

#include<stdlib.h>
#include<iostream>

using namespace std;

class inner {
public:
    inner(){
        cout<<"构建器"<<endl;
    }
    ~inner(){
        cout<<"析构器"<<endl;
    }
};

//int main(int argc,char* argv[]){
//
//    inner *p = new inner();
//    inner *pa = new inner[2];
//
//    delete p; //删除的是指针。
//    delete []pa;
//    return 0;
//}




