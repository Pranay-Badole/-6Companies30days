**Minimum Swaps to Arrange a Binary Grid**


Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.

A grid is said to be valid if all the cells above the main diagonal are zeros.

Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.

The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).


Solution:
Lets take an example of n = 4 (4 * 4), for all the top elements of the diagonal to be zeroes

\000   3 (n-1)
 \00   2 (n-2)
  \0   1 (n-3)
   \   0 (n-4)


we can see we atleast one row having consecutive right elements >= n-1 (here 3);
then we need atleast one row (excluding those used above) having consecutive right elements >= n-2. (here 2);
.
.
atleast one row (excluding those used above) having consecutive right elements >= 0;

so this is the basic intuition we only need the cnt of consecutive right elements of each row we dont need the whole matrix

So we will do that pre processing & get the cnt of each row and perform algorithm on that data.

so  for this input   
    1 1 1 1
    0 1 0 0
    1 1 1 0
    0 0 0 0

we will get = {0, 2, 1, 4}

so now we will iterate from i --> (n-1 to 0);
find the index (j) of first element in the array greater than equal to i;
and rotate the array to take it into the correct place add cost to tha ans.

if dont find any such element, we cant satisfy condition: return -1;




class Solution {
public:
    int minSwaps(vector<vector<int>>& v) {
        unordered_map<int, int> mp;
        int n = v.size();
        
        vector<int> all;
        
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = n-1; j >= 0; j--) {
                if(v[i][j] == 0) cnt++;
                else break;
            }
            all.push_back(cnt);    
        }
        int ans = 0;
        
        for(int i = n-1; i >= 0; i--) {
            // for(auto x : all) cout << x << ' ';
            // cout << endl;
            
            int need = i;
            int j = n - i - 1;
            for(j; j < n; j++) {
                if(all[j] >= i){
                    break;
                }
            }
            if(j == n) return -1;
            int st = n-i-1;
            
            // cout << "==>" << st << ' ' << j << endl;

            ans += (j - st);
            int t = all[j];
            for(j; j > st; j--){
                all[j] = all[j-1];
            }
            all[st] = t;
            
        }
        return ans;
    }
};