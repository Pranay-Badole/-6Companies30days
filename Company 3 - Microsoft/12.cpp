Que- Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number.


Soln-

Two Sum, but with little twist as in "2-sum" first sort the array.
as 2 sum algo works with 2 pointers(i.e 2 elements only) and we want quadrapule so we will choose
first 2 elements with bruteforce then apply the "2-sum" algo in the remaining elemnts to find the
suitable quadrapule.
as we want unique quadrapule we will maintain a set of vectors to prevent copies.

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &v, int t) {
        set<vector<int>> st;
        vector<vector<int>> ans;
        
        int n = v.size();
        sort(v.begin(), v.end());
        vector<int> last;
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1;j < n; j++) {
                int rem = t - v[i] - v[j]; 
                
                int l = j+1, r = n-1;
                while (l < r){
                    if(v[l] + v[r] > rem) r--;
                    else if(v[l] + v[r] < rem) l++;
                    else {
                        vector<int> temp = {v[i], v[j], v[l], v[r]};
                        if(!st.count(temp)){
                            st.insert(temp);
                            ans.push_back(temp);
                        }
                        l++;r--;
                    }
                }
            }
        }
        return ans;
    }
};