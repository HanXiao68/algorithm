//
//  leetcode_208 手写trie树.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/27.
//

private:
    bool isEnd;
    Trie* next[26];//每个节点都有字母表，表示下面的层级中是否有26字母
public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        memset(next,0,sizeof(next));
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (char c:word) {
            //如果之前的Trie树种没有出现，则新建一个节点来接上。
            if (node->next[c - 'a'] == NULL) {
                node->next[c - 'a'] = new Trie();
            }
            //如果找到的话，直接把指针移动到下一个节点的位置。
            node = node->next[c - 'a'];
        }
        //插入完了之后，把最后一个节点的标志位写成true.表示一个单词的结束
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        //要遍历这个单词的时候，需要用node节点来遍历这个Trie树
        Trie* node = this;
        for (char c:word) {
            node = node->next[c - 'a'];
            if (node == NULL) return false;
        }
        //以遍历这个单词为中心。最后判断最终的节点的状态。
        return node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        //前缀的算法是：这个prefix遍历完就true.但是遍历不完，就false
        Trie* node = this;
        for (char c:prefix) {
            node = node->next[c - 'a'];
            if (node == NULL) return false;
        }
        return true;
    }
