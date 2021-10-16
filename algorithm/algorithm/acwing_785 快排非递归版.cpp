//
//  acwing_785 快排非递归版.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/9.
//思路：
//两个指针从同一个方向走。
//cur指向当前元素，每次循环都要往前走，直到遍历完序列，所以循环结束的条件就是 cur < right ，right 为 序列的右边界。
//
//prev 指向cur的前一个位置。
//如果cur 指向的值小于 基准值， 那么就让 prev前进一个位置，并判断 cur 是否等于 prev，如果不等，说明它两不在同一位置，那么交换位置上的值。
//cur 要么相邻，要么中间间隔的都是别基准值大的元素。cur 的目的就是替prev 清理前进路上的障碍—“比基准值小的元素”。剩下的都是比基准值大的元素， 只要当 cur 找到比基准值小的，就放心的交换。
//循环结束时，需要将基准值，即序列的最后一个元素，与 prev下一个位置上的元素 交换。因为这个prev 所在的位置是比基准值小的元素，那么prev 的下一个位置一定比 prev 大，将这个比基准值大的元素与基准值交换就完成了一次划分。

//#include <stdio.h>
//#include <iostream>
//#include <stack>
//using namespace std;
//const int N =1e5+10;
//int a[N];
//
//int partition(int a[],int left,int right){
//    int prev = left -1;
//    int cur = left;
//    int key = a[right-1];
//    
//    while(cur < right)
//    {
//        if(a[cur] <key && ++prev !=cur) swap(a[cur],a[prev]);
//        
//        cur++;
//    }
//    if(a[++prev] != key) swap(a[prev],a[right-1]);
//    return prev;
//}
//
//void quickSort(int a[],int left,int right){
//    if(left >=right) return ;
//    stack<int> s;
//    s.push(left);
//    s.push(right);
//    
//    while(!s.empty()){
//        int r = s.top(); s.pop();
//        int l = s.top();s.pop();
//        
//        if(l<r){
//            int pivod = partition(a,l,r);
////            手动压栈。
////            左半部分
//            s.push(l);
//            s.push(pivod);
////            有半部分
//            s.push(pivod+1);
//            s.push(r);
//        }
//    }
//}
//
//int main(){
//    
//    int n;
//    cin>>n;
//    for(int i=0;i<n;i++) cin>>a[i];
//    
//    quickSort(a,0,n-1);
//    
//    for(int i=0;i<n;i++) cout<<a[i]<<" ";
//    return 0;
//}


