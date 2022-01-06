Que-

// You may recall that an array arr is a mountain array if and only if:

// arr.length >= 3
// There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

// Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.



Soln: the key here is to note that next mountain will start only after the first ends
    so for every mountain we will find 3 points l, m, r such that "l < m < r"


        m
       /\
      /  \
     /    \ r
  l /      


class Solution {
public:
    int longestMountain(vector<int>& v) {
        int n = v.size();
        int l = 0;
        int ans = 0;
        
        while(l < n) {
            int m = l;
            while(((m + 1) < n) && (v[m] < v[m+1])) {
                m++;
            }
            int r = m;
            while(((r + 1) < n) && (v[r] > v[r+1])){
                r++;
            }
            // cout << l << ' ' << m << ' ' << r << endl;
            if((l < m) && (m < r)){
                ans = max(ans, (r - l + 1));
            }

        // next mountain's start point 'l' will be prev mountain's point 'r'
        // note for case where l = m = r; we must go to l+1, else infinite loop

            l = max(l+1, r);
        }
        return ans;
    }
};