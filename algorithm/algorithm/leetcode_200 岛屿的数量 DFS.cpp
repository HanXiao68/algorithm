//
//  leetcode_200 岛屿的数量 DFS.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/19.
//

class Solution {
public:

    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0 ||i>=grid.size() ||j<0 ||j>=grid[0].size()||grid[i][j]=='0') return;

        grid[i][j] ='0';
        int di[4] = {1,-1,0,0};
        int dj[4] = {0,0,1,-1};
        // 这里面的变量重复了。使用k或者index
        for(int k=0;k<4;k++){
            dfs(grid,i+di[k],j+dj[k]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans =0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] =='1'){
                    ans++;
                    dfs(grid,i,j);
                }
                    
            }
            
        }
        return ans;
    }
};
