//
//  200 505 迷宫2（DFS求路径长度）.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/24.
//

class Solution {
public:
    typedef pair<int,int> PII;
    int shortestDistance(vector<vector<int>>& a, vector<int>& start, vector<int>& dest) {
        return bfs(a,start,dest);
    }

    int bfs(vector<vector<int>>& a, vector<int>& start, vector<int>& dest){
        int row = a.size();int col = a[0].size();
        vector<vector<long long>> visited(row,vector<long long> (col,INT_MAX));
        queue<PII> q;
        q.push(PII{start[0],start[1]});
        visited[start[0]][start[1]] = 0;

        while(q.size()){
            auto temp = q.front();int r = temp.first;int c = temp.second;q.pop();
            int dx[4] ={0,0,-1,1};int dy[4] = {1,-1,0,0};
            for(int i=0;i<4;i++){
                int nc = c +dy[i];int nr = r +dx[i];
                int step =1;
                while(nr>=0 && nr<row &&nc>=0&&nc<col&&a[nr][nc] ==0){
                    nr +=dx[i];nc += dy[i];
                    step++;
                }
                nr -=dx[i];
                nc -=dy[i];
                step--;
                if(visited[r][c]+step < visited[nr][nc]){
                   
                    visited[nr][nc] = visited[r][c]+step;
                     q.push(PII {nr,nc});
                }
            }
        }
        if(visited[dest[0]][dest[1]] != INT_MAX) return visited[dest[0]][dest[1]];
        else return -1;
    }
    
};
