//
//  leetcode_297 二叉树的序列化和反序列化.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

   // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();

            if (node) {
                res += to_string(node->val) + ' ';
                q.push(node->left);
                q.push(node->right);
            } else {
                res += "null ";
            }
            q.pop();
        }

        // cout << res;
        return res;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> list;
        for (int l = 0, r = 0; l < data.size(); ) {
            r = l;
            while (data[r] != ' ') r ++ ;
            if (data[l] == 'n') {
                l = r + 1;
                list.push_back(NULL);
                continue;
            }
            int val = 0, sign = 1;
            if (l < r && data[l] == '-') sign = -1, l ++ ;
            for (int i = l; i < r; i ++ ) val = val * 10 + data[i] - '0';
            val *= sign;
            l = r + 1;
            auto newNode = new TreeNode(val);
            list.push_back(newNode);
        }
        
        auto newList = list[0];
        auto curNode = newList;
        
        // j表示当前的根节点，遇到null就递进
        // i表示当前的孩子节点，相邻两个构成一个父节点的孩子节点
        for (int i = 1, j = 1; j < list.size() && i < list.size(); j ++ ) {
            if (!curNode) {
                curNode = list[j];
                continue;
            }
            curNode->left = list[i];
            curNode->right = list[i + 1];
            curNode = list[j];
            i += 2;
        }

        return newList;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
