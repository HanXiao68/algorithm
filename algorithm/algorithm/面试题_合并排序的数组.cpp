//
//  面试题_合并排序的数组.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/20.
// 就按照 归并排序，额外空间的方法做。O(1)空间会覆盖以前A数组的值。不可取。

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        vector<int> temp(n+m);
        int i=0;//A  m
        int j =0;//B  n
        int k = 0;
        while(i<m && j<n){
            if(A[i]<=B[j])
                
                temp[k++] = A[i++];
            else
                temp[k++] = B[j++];
        }
        while(i<m) {temp[k] = A[i]; k++;i++;}
        while(j<n) {temp[k] = B[j]; k++;j++;}
        for(int i=0;i<n+m;i++) A[i] = temp[i];
    }
};
