//
//  leetcode_48 旋转图像.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 先左右翻转，再对角线翻转
        int len = matrix.size();
        int mid = (len-1)/2;
        //flip over x = len/2
        for(int i=0; i<len; i++){
            for(int j=0; j<=mid; j++){
                swap(matrix[i][j],matrix[i][len-1-j]);
            }
        }
        //flip over diag
        for(int i=0; i<len; i++){
            for(int j=0; j<len-1-i; j++){
                swap(matrix[i][j],matrix[len-1-j][len-1-i]);
            }
        }
    }
};
