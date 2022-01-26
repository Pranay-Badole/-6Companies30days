**Number of Provinces**

There are n cities. Some of them are connected, while some are not. 
If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.


Solution-
This is basically finding no of connected components in an undirected graph.
The graph is given in the form of adjancey matrix.

so we dont need to do any preprocessing just do dfs and maintain a visited list.


class Solution {
public:
    
    void dfs(int i, vector<vector<int>> &v, vector<int> &vis) {
        int n = v.size();
        
        vis[i] = 1;
        for(int j = 0; j < n; j++) {
            if(v[i][j] && !vis[j]) {
                dfs(j, v, vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& v) {
        int n = v.size();
        vector<int> vis(n, 0);
        int cnt = 0;
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                cnt++;
                dfs(i, v, vis);
            }
        }
        return cnt;
    }
};