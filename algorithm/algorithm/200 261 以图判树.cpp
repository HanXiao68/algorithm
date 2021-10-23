//
//  200 261 以图判树.cpp
//  algorithm
//
//  Created by 韩霄 on 2021/10/23.
// 并查集，判断能否形成一个合法的树结构

class Unoin
{
private:
    vector<int> parent;
public:
    Unoin(int n)
    {
        parent.resize(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
    }
    int find(int index)
    {
        if(index==parent[index])
            return index;
        parent[index]=find(parent[index]);
        return parent[index];
    }
    bool unions(int index1,int index2)
    {
        int p1=find(index1);
        int p2=find(index2);
        if(p1==p2)
            return false;
        parent[p1]=p2;
        return true;
    }
    bool diff()  //判断有几个根节点，如果超过一个那就是森林，不是树
    {
        int cnt=0;
        int n=parent.size();
        for(int i=0;i<n;i++)
            if(parent[i]==i)
                cnt++;
        return cnt==1;
    }
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges)
    {
        Unoin u(n);
        for(auto edge:edges)
        {
            if(!u.unions(edge[0],edge[1]))
                return false;
        }
        if(u.diff())
            return true;
        else
            return false;
    }
};

作者：Miyuki_Kazuya
链接：https://leetcode-cn.com/problems/graph-valid-tree/solution/czhi-bing-cha-ji-by-miyuki_kazuya-8p3r/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
