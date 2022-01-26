**Pacific Atlantic Water Flow**

There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. 
The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] 
represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west 
if the neighboring cell's height is less than or equal to the current cell's height. 
Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.


Solution-

as we are given in the problem that we have to return cells reacheable from both top-left cells and bottom right cells.

So there can be many different approaches.
Here are 2 below:

1. Multi Source BFS: 
    We can start BFS from the extreme cells i.e top left cells and bottom right cells separately.
    and get all the cells reacheable from both the oceans individually then we just need the intersection of both the sets and get the answer.

2. DFS:
    Traverse throught all the cells and check if we can satisfy both the conditions for this cell i.e
    (i) able to reach top - left cells.
    (ii) able to reach bottom - right cells.
    if this cell is valid add it to the set.


class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    bool check1(int i, int j, int prev, vector<vector<int>> &v, vector<vector<int>> &pos, int &m, int &n){
        if(i < 0 || j < 0) return 1;
        if(i >= m || j >= n || v[i][j] > prev) return 0;
        
        if(pos[i][j] == 1) return pos[i][j];
        
        int ans = 0;
        int temp = v[i][j];
        v[i][j] = INT_MAX;
        
        for(int z = 0; z < 4; z++) {
            int x = i + dx[z];
            int y = j + dy[z];
            ans = (ans | check1(x, y, temp, v, pos, m, n));
            
        }
        v[i][j] = temp;
        return pos[i][j] = ans;
     }
    bool check2(int i, int j, int prev, vector<vector<int>> &v, vector<vector<int>> &pos, int &m, int &n){
        if((i >= m) || (j >= n)) { return 1;}
        if(i < 0 || j < 0 || v[i][j] > prev) return 0;
        // cout << i << ' ' << j << endl;
        
        if(pos[i][j] == 1) return pos[i][j];
        
        int ans = 0;
        int temp = v[i][j];
        v[i][j] = INT_MAX;
        
        for(int z = 0; z < 4; z++) {
            int x = i + dx[z];
            int y = j + dy[z];
            ans = (ans | check2(x, y, temp, v, pos, m, n));
        }
        v[i][j] = temp;
        return pos[i][j] = ans;
     }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& v) {
        
        int m = v.size();
        int n = v[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> pos1(m, vector<int>(n, -1));
        vector<vector<int>> pos2(m, vector<int>(n, -1));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                check1(i, j, INT_MAX, v, pos1, m, n);
                if(check1(i, j, INT_MAX, v, pos1, m, n) && check2(i, j, INT_MAX, v, pos2, m, n)){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};