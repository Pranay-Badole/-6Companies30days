Que-
Given a matrix of size r*c. Traverse the matrix in spiral form.


standard implementation stuff
l, r, u, d  :: will represents the boundaries of elements left to be printed,
the boundary that should be printed will be maintained in a char ch;


class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> v, int p, int c) 
    {
        vector<int> ans;
        int m = v.size();
        int n = v[0].size();
        
        int l = 0, r = n - 1;
        int u = 0, d = m - 1;
        
        char ch = 'R';
        // int z = 1;
        while(1) {
            if(l > r || u > d) break;
            if(ch == 'R'){
                for(int i = l; i <= r; i++) {
                    ans.push_back(v[u][i]);
                    // cout << v[u][i] << ' ';
                }
                ch = 'D';
                u++;
            }
            else if(ch == 'D'){
                for(int i = u; i <= d; i++) {
                    ans.push_back(v[i][r]);
                    // cout << v[i][r] << ' ';
                }
                ch = 'L';
                r--;
            }
            else if(ch == 'L'){
                for(int i = r; i >= l; i--) {
                    ans.push_back(v[d][i]);
                    // cout << v[d][i] << ' ';
                }
                ch = 'U';
                d--;
            }
            else{
                for(int i = d; i >= u; i--) {
                    ans.push_back(v[i][l]);
                    // cout << v[i][l] << ' ';
                }
                ch = 'R';
                l++;
            }
        }
        return ans;
    }
};