Que-
// find the maximum score for each and every contiguous sub-list of size K to strategize for the game.


// for range queries the most appropriate DS is segement tree
// to find max, min, sum.... we can insert a element in log(N) and perform funtion in log(N) as well
// but we can also use a monotonic deque O(n) if we have to perform a funciton() for a constant
// range k so here we use deque and maintain it as a monotonic one (to be specific in decreasing order as we want max)
// first element will always correspond to the max ele in the current sub-list of size k;


#define sz(x)    (int)x.size()
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> v, int n, int k) {
        vector<int> ans;
        deque<int> dq;
        int i;
        for(i = 0; i < k; i++) {
            while(sz(dq) && v[dq.back()] <= v[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for(i; i < n; i++) {
            ans.push_back(v[dq.front()]);
            while(sz(dq) && dq.front() <= (i - k)) {
                dq.pop_front();
            }
            while(sz(dq) && v[dq.back()] <= v[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(v[dq.front()]);
        return ans;
    }
};