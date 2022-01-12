Que-
Given a grid of dimension nxm containing 0s and 1s. Find the unit area of the largest region of 1s.
Region of 1's is a group of 1's connected 8-directionally (horizontally, vertically, diagonally).


Soln-
// simple dfs solution keeping track of visited 1's 
// all connected components of '1's will be visited in one single iteration next component in another iteration and so on..

class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int dx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
    int dy[8] = {1, 0, -1, 0, 1, 1, -1, -1};
    
    bool check(int i, int j, vector<vector<int>> &v, vector<vector<int>> &vis){
        
        if(i < 0 || j < 0 || i >= v.size() || j >= v[0].size()){
            return 0;
        }
        if(v[i][j] == 0 || vis[i][j] == 1) return 0;
        return 1;
    }
    
    int dfs(int i, int j, vector<vector<int>> &v, vector<vector<int>> &vis) {
        
        int ans = 1;
        vis[i][j] = 1;
        
        for(int z = 0; z < 8; z++) {
            if(check(i+dx[z], j+dy[z], v, vis)){
                ans += dfs(i+dx[z], j+dy[z], v, vis);
            }
        }
        
        return ans;
    }
    
    int findMaxArea(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        int ans = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(v[i][j] == 1 && !vis[i][j]){
                    ans = max(ans, dfs(i, j, v, vis));
                }        
            }
        }
        return ans;
    }
};