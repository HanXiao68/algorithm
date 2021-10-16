//
//  acwing_96 不同的二叉搜索树1.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/16.
// 总的方案个数 = 数组中左边的左子树方案数 * 数组中右边的右子树方案数
//解法：递归求解
#include<vector>

using namespace std;

class Solution {
public:
    
    int numTrees(int n) {
        if(n ==0) return 1;
        vector<int> f(n+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                f[i] += f[j-1] *f[i-j];
            }
        }
        return f[n];
    }
    
};
