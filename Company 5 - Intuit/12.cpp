**Course Schedule II**

Que-
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. 
If it is impossible to finish all courses, return an empty array.

Solution-
Convert the relations given, into graph using adjancey list.
then return topological sort of the graph but make sure to check the presence of cycle in the graph.
If there is cycle then we cant get the answer.

class Solution {
public:
    
    void dfs(int i, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st, int &flag) {
        if(vis[i] == 1){flag = 1;return;}
        if(vis[i] == 2){return;}
        
        vis[i] = 1;
        for(auto &to : adj[i]) {
            dfs(to, vis, adj, st, flag);
        }
        st.push(i);
        vis[i] = 2;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& v) {
        vector<vector<int>> adj(n);
        vector<int> ans;
        
        for(auto x: v){
            adj[x[1]].push_back(x[0]);
        }

        stack<int> st;
        vector<int> vis(n, 0);
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                int flag = 0;
                dfs(i, vis, adj, st, flag);
                if(flag){
                    vector<int> res = {};
                    return res;
                }
            }
        }
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};