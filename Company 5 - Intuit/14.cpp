**As Far from Land as Possible**


Que- Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, 
find a water cell such that its distance to the nearest land cell is maximized, and return the distance. 
If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.



Solution-
Multi source BFS, with starting elements in the queue as the cells having value = 1;
then we can just find the most farther element = 0 from all the 1s.



class Solution {
public:
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    int maxDistance(vector<vector<int>>& v) {
        
        int n = v.size();
        
        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<int, int>> q;
        
        for(int i = 0;i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(v[i][j] == 1){
                    vis[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        if((q.size() == 0) || (q.size() == n*n)) return -1;
        
        int mx = 0;
        while(q.size()) {
            int m = q.size();
            while(m--) {
                auto top = q.front();
                q.pop();
                
                for(int i = 0; i < 4; i++) {
                    int nx = top.first + dx[i];
                    int ny = top.second + dy[i];
                    if(nx < 0 ||  ny < 0 || nx >= n || ny >= n || vis[nx][ny] || v[nx][ny] == 1) {
                        continue;
                    }
                    vis[nx][ny] = vis[top.first][top.second] + 1;
                    mx = max(mx, vis[nx][ny]);
                    q.push({nx, ny});
                }
            }
        }

        return mx;
    }
};