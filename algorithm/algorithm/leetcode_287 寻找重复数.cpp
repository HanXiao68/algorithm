//
//  leetcode_287 寻找重复数.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/19.
//
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 转换成了有环的链表的入口节点的题。因为有重复的数，且都在 1，n 内 必然存在环
        int a = 0, b = 0;
        while (true) {
            a = nums[a];
            b = nums[nums[b]];
            if (a == b) {
                a = 0;
                while (a != b) {
                    a = nums[a];
                    b = nums[b];
                }
                return a;
            }
        }

        return -1;
    }
};
