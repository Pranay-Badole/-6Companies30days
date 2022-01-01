// Que
// Given an array of positive numbers, the task is to find the number 
// of possible contiguous subarrays having product less than a given number k.

#define  ll      long long 

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        ll l = 0, r = 0;
        double prod = 1.0;
        int ans = 0;
        
        while(l < n){
            r = max(r, l);
            while(r < n){

// this is to prevent integer overflow might give RTE / MLE if used "(prod * a[r]) < k"
// and using double for precison else WA

                double div = ((k * 1.0) / a[r]); 
                if(prod < div){ 
                    prod *= a[r];
                    r++;
                }
                else break;
            }

            ans += max(0ll, (r - l));
            if(l != r) prod = (prod / a[l]);
            l++;
        }
        return ans;
    }
};