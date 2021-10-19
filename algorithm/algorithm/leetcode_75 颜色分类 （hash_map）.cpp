//
//  leetcode_75 颜色分类 （hash_map）.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/19.
//

class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> m;
        for(auto x:nums){
            m[x]++;
        }
        for(int i=0,j=0;i<m.size();i++){
            while(m[i]--){
                nums[j++] = i;
            }
        }
    }
};
