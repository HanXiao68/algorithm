//
//  200 1213 三个有序数组的交集.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/23.
//

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
         vector<int> res;
        unordered_map<int, int> hash;

        for (int i = 0; i < arr1.size() || i < arr2.size(); i ++ )  //先把前两个数组加入哈希表
        {
            if (i < arr1.size()) hash[arr1[i]] ++ ;
            if (i < arr2.size()) hash[arr2[i]] ++ ;
        }

        for (int x : arr3)              //遍历第三个数组
            if (hash[x] == 2)           //若当前数字已出现过两次，则为交集，加入输出数组中
                res.push_back(x);

        return res;
    }
};
