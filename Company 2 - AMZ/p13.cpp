Que- Rotting Oranges


// tried using dfs but it gives bad complexity
// bfs, priority queue is better

class Solution {
public:
    
    void dfs(int cur, int i, int j, vector<vector<int>> &v, vector<vector<int>> &ans, vector<vector<int>> &vis) {
        if(i < 0 || j < 0 || i >= v.size() || j >= v[0].size()) {
            return ;
        }
        
        if(vis[i][j] || (v[i][j] != 1)){return;}
        
        if(cur >= ans[i][j]){return;}
        
        ans[i][j] = min(ans[i][j], cur);
        vis[i][j] = 1;
        
        dfs(cur + 1, i + 1, j, v, ans, vis);
        dfs(cur + 1, i - 1, j, v, ans, vis);
        dfs(cur + 1, i, j + 1, v, ans, vis);
        dfs(cur + 1, i, j - 1, v, ans, vis);
        
        vis[i][j] = 0;
    }
    
    int orangesRotting(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                vector<vector<int>> vis(m, vector<int>(n, 0));
                if(v[i][j] == 2){
                    // cout << i << ' ' << j;
                    // dfs(0, i, j, v, ans, vis);
                    dfs(1, i + 1, j, v, ans, vis);
                    dfs(1, i - 1, j, v, ans, vis);
                    dfs(1, i, j + 1, v, ans, vis);
                    dfs(1, i, j - 1, v, ans, vis);
                }
            }
        }
        // cout << endl;
        int res = 0;
        
         for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // cout << ans[i][j] << ' ';
                if(v[i][j] == 1 ){
                    if(ans[i][j] == INT_MAX) return -1;
                    res = max(res, ans[i][j]);
                }   
            }
             // cout << endl;
        }
        return res;
    }
};