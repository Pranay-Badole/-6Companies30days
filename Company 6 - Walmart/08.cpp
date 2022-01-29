**Maximum Height Tree**

Given N dots that form a triangle such that ith line contains i number of dots.

    .
   . .
  . . .
 . . . .

Find the minimum height H of the triangle that can be formed using these N dots.


Solution:
We smell monotonicity use Binary Search. 
The no of dots till mth line will be : 1 + 2 + 3 + 4 + ..... + m
 = (m * (m+1))/2
 
if it satisfy N then try for greater than m.
else try for less than m

class Solution{
public:
    int height(int N){
        int l = 0, r = 1e3;
        int ans;
        
        while(l <= r) {
            int mid = l + (r - l)/2;
            if(mid * (mid + 1) <= 2 * N){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return ans;
    }
};