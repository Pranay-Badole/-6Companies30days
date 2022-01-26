**Number of Boomerangs**
You are given n points in the plane that are all distinct, where points[i] = [xi, yi]. 
A boomerang is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Return the number of boomerangs.

Solution-
as we have to find tuples (i, j, k) such that j and k are equidistant from i.
So we will iterate over all i and find distance of all the points from a particular point i, and store it in hashmaps where {key, val} --> {dist, cnt};

so for a dist having cnt = 't'
the no of tuples will be t*(t-1)/2;
(picking two points out of cnt i.e tC2)

order of points matter here so every tuple will be counted twice.

(i, j, k) && (i, k, j);

so at last multiply ans with 2;
ans *= 2;

return the ans;




class Solution {
public:
    
    int numberOfBoomerangs(vector<vector<int>> &v) {
        int cnt = 0;
        
        int n = v.size();
        int ans = 0;
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n; i++) {
            mp.clear();
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                int x = v[j][1] - v[i][1];
                int y = v[j][0] - v[i][0];
                int dist = (x * x) + (y * y);
                mp[dist]++;
            }
            for(auto x : mp){
                int t = x.second;
                ans += t*(t - 1)/2;
            }
        }
        ans *= 2;
       return ans;
    }
};