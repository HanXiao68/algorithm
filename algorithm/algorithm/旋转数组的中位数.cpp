//
//  旋转数组的中位数.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/21.
//

#include <stdio.h>
#include <iostream>

using namespace std;

double mid_num(int a[],int n){
    
    int l = 0;
    int r  = n-1;
    while(l < r){
        int mid = (l+r)>>1;
        
        if(a[r]>=a[mid]) r= mid;
        else if(a[r]<a[mid]){
            l = mid+1;
        }
    }
    int size = n;
    if(size %2 ==1){
        return a[(l +size/2)%size];
    }else{
        return (double)(a[(l+size/2)%size] +a[(l+size/2-1)%size]) /2;
    }
    
    
}
int main(){
    
    int a[] = {6,7,8,1,2,3,4,5,9};
    
    double res = mid_num(a,9);
    
    cout<<res<<endl;
    return 0;
}


