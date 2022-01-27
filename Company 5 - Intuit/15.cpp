**Koko Eating Bananas**

Que-
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.


Solution-

Whenever it is asked to find the minimum or maximum answer. 
Leave everything aside and take a moment and try to think if "Binary Search on answer concept" can be applicable in that problem.
Because you will be wasting a lot of time thinking of a greedy approach (mostly linear time complexity) 
but the key was to identify the monotonicity of the problem and use BS;




class Solution {
public:
    
    bool check(int s, vector<int> &piles, int &h) {
        int time_taken = 0;
        for(auto &x : piles) {
            time_taken += ceil((1.0*x)/s);
            if(time_taken > h) return 0;
        } 
        return 1;
        
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int mx = 0;
        for(int i = 0; i < piles.size(); i++){
            mx = max(mx, piles[i]);
        }
        
        int l = 1, r = mx;
        int ans;
        
        while(l <= r){
            int mid = l + (r - l)/2;
            if(check(mid, piles, h)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};

