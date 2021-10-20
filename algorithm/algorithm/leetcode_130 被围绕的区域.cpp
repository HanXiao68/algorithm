//
//  leetcode_130 被围绕的区域.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/20.
// 时间：O(n*m)  空间： O(n*m)

class Solution {
public:

    private:
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == 'X' || board[i][j] == '#') {
            // board[i][j] == '#' 说明已经搜索过了
            return;
        }
        board[i][j] = '#';
        dfs(board, i - 1, j);    // 上
        dfs(board, i + 1, j);    // 下
        dfs(board, i, j - 1);    // 左
        dfs(board, i, j + 1);    // 右

    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 从边缘O开始搜索
                bool isEdge = i == 0 || j == 0 || i == m - 1 || j == n - 1;
                if (isEdge && board[i][j] == 'O') {
                    dfs(board, i, j);
                }
            }
        }
        for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            cout<<board[i][j]<<" ";
         }
         cout<<endl;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
