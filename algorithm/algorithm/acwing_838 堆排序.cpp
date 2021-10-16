//
//  acwing_838 堆排序.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/13.
//这道题想要考的是 用数组实现。upper（）和down()

#include <iostream>
#include<algorithm>

using namespace std;

const int N =1e5+10;
int a[N],sz;


void down(int u){
//    1.要用t的这个变量原因：如果左子节点已经比根节点大了，那么第二个if时这个t代表的时候根节点和左子节点中最大的数的下标；而不仅仅是根节点的下标。2.用于判断这个数是否需要进行上浮。
    int t = u;//从u这个位置开始
//    需要下沉交换的情况：左子节点比gen
    if(u*2 <=sz &&a[u*2]<a[t]) t = u*2;
    if(u*2 +1 <=sz && a[u*2+1]<a[t]) t = u*2 +1;
    if(u != t){
        swap(a[u],a[t]);
        down(t);
    }
}
int main(){
    
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
//    从非叶子结点最后一层，即倒数第二层开始。
    sz = n;
    for(int i=n/2;i>=1;i--) down(i);
    
    while(m--){
        cout<<a[1]<<" ";
        a[1] = a[sz]; //其实也不用交换。反正a数组里下一次建堆的时候也没有a[sz]参加。
        sz--;
        down(1);//从第一个数开始继续，重新小顶堆
    }
    return 0;
}














//调用stl的multiset库
//#include <stdio.h>
//#include <iostream>
//#include <set>
//using namespace std;
//int n,m;
//const int N =1e5+10;
//multiset<int> s;
//int main(){
//    cin>>n>>m;
//    for(int i=0;i<n;i++){
//        int x;cin>>x;
//        s.insert(x);
//    }
//    for(auto x:s) {
//        if(m--)
//            cout<<x<<endl;
//        else break;
//    }
//
//    return 0;
//}


