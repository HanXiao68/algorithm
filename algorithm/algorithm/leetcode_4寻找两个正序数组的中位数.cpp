//
//  leetcode_4寻找两个正序数组的中位数.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         int total = nums1.size() + nums2.size();
        if (total % 2 == 0)
        {
            int left = find(nums1, 0, nums2, 0, total / 2);
            int right = find(nums1, 0, nums2, 0, total / 2 + 1);
            return (left + right) / 2.0;
        }
        else
        {
            return find(nums1, 0, nums2, 0, total / 2 + 1);
        }

    }
    //参数：第一个数组，开始的位置，第二个数组，开始的位置，要找的位置的数
    int find(vector<int >& nums1,int i,vector<int>& nums2,int j,int k){
        // 保证nums1的长度小于nums2的长度
        if(nums1.size() - i >nums2.size() -j) return find(nums2,j,nums1,i,k);
        // 边界情况，就剩一个数字
        if(k==1){
            if(nums1.size() == i) return nums2[j];
            else return min(nums1[i],nums2[j]);
        }

        if(nums1.size() ==i) return nums2[j+k-1]; //nums1空了。就返回nums2的第一个元素
        int si  = min((int)nums1.size(),i+k/2),sj = j+k-k/2; //两个数组的中间的位置。
        if(nums1[si-1] > nums2[sj-1])
            return find(nums1,i,nums2,sj,k-(sj-j));
        else
            return find(nums1,si,nums2,j,k-(si-i));


    }
