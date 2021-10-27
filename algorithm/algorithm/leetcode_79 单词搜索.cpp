//
//  leetcode_79 单词搜索.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

class Solution {
public:
    bool exist(vector<vector<char>> board,string word) {
        for (int i = 0; i < board.size();i++) {
            for (int j = 0; j < board[0].size();j++) {
                if (dfs(board,word,0,i,j)) return true;
            }
        }
        return false;
    }
    int dx[4] = { 1,-1,0,0 }, dy[4] = {0,0,1,-1};
    //这里的level理解为字符串单词递归的层级更为恰当
    bool dfs(vector<vector<char>>& board,string& word,int level,int x,int y) {
        if (board[x][y] != word[level]) return false;
        if (level == word.size() - 1) return true;
        
        char t = board[x][y];
        //这里写是一个trick点。在当前遍历的路径中，为了不让重复。要把每个遍历过得字符都换为  .
        //并且最后完了后要恢复现场，为了下一个起点位置进dfs的时候不影响。
        board[x][y] = '0';
        for (int i = 0; i < 4;i++) {
            int a = x + dx[i]; int b = y + dy[i];
            if(a>=0 && a<board.size() & &b>=0 && b<board[a].size())
                if (dfs(board,word,level+1,a,b)) return true;
        
        }
        board[x][y] = t;
        return false;
    }
};
