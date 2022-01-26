**Capacity To Ship Packages Within D Days**

Que- 
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. 
Each day, we load the ship with packages on the conveyor belt (in the order given by weights). 
We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.


Solution:
Binary Search on answer
same as "allocate min no of pages"


bool isfeasible(vector<int> &v, int mid, int D){
    int cnt=1;
    int sum=0;
    for(int i = 0; i < v.size(); i++) {
        sum += v[i];
        if(sum > mid){
            cnt++;
            sum = v[i]; 
        }
    }
    if(cnt>D){return false;}
    return true;
}

class Solution {
public:
    int shipWithinDays(vector<int>& v, int D) {
        int l = -1, r = 0;
        for(auto &x : v){
            l = max(l,x);
            r += x;
        } 
        int ans = 0;
        while(l <= r){
            int mid = l + (r-l)/2;
            
            if(isfeasible(v,mid,D)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};