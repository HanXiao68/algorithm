//
//  200 490 迷宫.cpp
//  algorithm
//  Created by 韩霄 on 2021/10/23.
#include <vector>
#include <queue>

////经典BFS写法。
using namespace std;
//
//class Solution {
//public:
//    typedef pair<int,int> PII;
//    bool hasPath(vector<vector<int>>& a, vector<int>& start, vector<int>& dest) {
//        return bfs(a,start,dest);
//    }
//
//    bool bfs(vector<vector<int>>& a, vector<int>& start, vector<int>& dest){
//        int row = a.size();int col = a[0].size();
//        vector<vector<bool>> visited(row,vector<bool> (col,false));
//        queue<PII> q;
//        q.push(PII{start[0],start[1]});
//        visited[start[0]][start[1]] = true;
//
//        while(q.size()){
//            auto temp = q.front();int r = temp.first;int c = temp.second;q.pop();
//            if(r == dest[0] &&c ==dest[1]) return true;
//
//            int dx[4] ={0,0,-1,1};int dy[4] = {1,-1,0,0};
//            for(int i=0;i<4;i++){
//                int nc = c +dy[i];int nr = r +dx[i];
//                while(nr>=0 && nr<row &&nc>=0&&nc<col&&a[nr][nc] ==0){
//                    nr +=dx[i];nc += dy[i];
//                }
//                nr -=dx[i];
//                nc -=dy[i];
//                if(visited[nr][nc] == false){
//                    q.push(PII {nr,nc});
//                    visited[nr][nc] = true;
//                }
//            }
//        }
//        return false;
//    }
//};


//经典DFS写法
class Solution{
public:
    int row,col;
    int dest_r,dest_c;
    vector<vector<bool>> visited;
    bool hasPath(vector<vector<int>>& a, vector<int>& start, vector<int>& dest)
       {
            row = a.size();col =a[0].size();
            dest_r = dest[0];dest_c = dest[1];
            visited = vector<vector<bool>>(row,vector<bool> (col,false));
            return dfs(a,start[0],start[1]);
        }
    bool dfs(vector<vector<int>>& a, int r,int c){
        if(r == dest_r &&c ==dest_c) return true;
        int dx[4] ={0,0,1,-1};int dy[4] ={1,-1,0,0};;
        for(int i =0;i<4;i++){
            int nr =r+dx[i];int nc = c +dy[i];
            while(nr>=0 &&nr<row &&nc>=0&&nc<col &&a[nr][nc] == 0){
                nr +=dx[i];
                nc +=dy[i];
            }
            nr -=dx[i];
            nc -=dy[i];
            if(visited[nr][nc]==false){
                visited[nr][nc] =true;
//                下面这句就是dfS和bfs的区别。dfs是递归调用。bfs是队列queue手动遍历。
                if(dfs(a,nr,nc) ==true) return true;
                visited[nr][nc] =true;
            }
        }
        return false;
    }
};




