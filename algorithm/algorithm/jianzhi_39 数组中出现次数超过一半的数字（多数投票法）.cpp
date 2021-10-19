//
//  多数投票法）.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/19.
//

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    
        int count=0;
        int num = -1;
        for(int i=0;i<numbers.size();i++){
            if(num == numbers[i]) ++count;
            else if(--count <0){
                num = numbers[i];
                count =1;
            }
        }
        return num;
    }
};
