//
//  acwing_844 走迷宫DFS.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/20.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;
const int N = 110;
int n,m;
int res;
int ans =0;
int d[N][N];


typedef pair<int,int> PII;
int dfs(vector<vector<int>>& grid,int cur_i,int cur_j){
    
    queue<PII> q;
    
    d[0][0] = 0;
    q.push({0,0});
    int dx[4] = {1,-1,0,0};int dy[4] = {0,0,1,-1};
    while(q.size()){
        auto temp = q.front();q.pop();
        for(int i=0;i<4;i++){
            int x = temp.first+dx[i];
            int y = temp.second+dy[i];
            if(x>=0 &&x<n &&y>=0&&y<m && grid[x][y]!=1 && d[x][y] ==-1)
            {
                d[x][y] = d[temp.first][temp.second] +1;
                q.push({x,y});
            }
        }
    }
    return d[n-1][m-1];
}
int main(){
    cin>>n>>m;
//    vector<vector<int>> vec(m, vector<int>(n, 0));
    vector<vector<int>> grid(N,vector<int>(N,0));
    memset(d,-1,sizeof d);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>grid[i][j];
    }
    
    cout<<dfs(grid,1,1)<<endl;
    
    return 0;
}
