//
//  acwing_KMP求模式串在母串中的所有起始位置.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/11.
//关键是求模式串的ne【】数组。关键是求以p[i]为结尾的p的后缀串与p的前缀串的最大匹配的长度，就是下一次p串要移动的长度。
//一旦模式串中间匹配p[i]失败了，那么以p[i-1]为结尾的串中和模式串的前缀串最大的相同的长度，就是模式串需要往后移动的长度。
//匹配失败后最少的移动距离就是最大的匹配长度。ne数组存的就是这个长度。
//时间复杂度是O(2m)--->O(N)
#include <stdio.h>
#include <iostream>

using namespace std;
int n,m;
const int N = 1e5+10,M =1e6+10;
char p[N],s[M]; //s串表示原字符串，p表示模式串
int ne[N];
int main(){
    cin>>n>>(p+1)>>m>>(s+1); //s串和p串都是从s[1] p[1]开始存的。
//    求ne数组,i=1的时候不用算。第一个数没匹配则从0开始。
//    且必须不能从i=1开始，会进入死循环。要从2开始。
    for(int i=2,j=0;i<=n;i++){
        while (j &&p[i] != p[j+1]) j = ne[j];
//        匹配成功，继续往后走
        if(p[i] == p[j+1]) j++;
//      记录模式串每个位置的ne【i】。
        ne[i] = j;
        
    }
    
//    KMP的匹配过程
    for(int i=1,j=0;i<=m;i++)
    {
        while(j && s[i] !=p[j+1]) j = ne[j];
        if(s[i] == p[j+1]) j++;
        
        if(j ==n)
        {
            cout<<i-n<<" ";
//     匹配成功后，再往后退一步。含义是：当前匹配成功了。往下走记录下一个能撇皮的位置在哪里。
            j = ne[j];
        }
    }
    
    return 0;
}
