**Find in Mountain Array**

Que- (This problem is an interactive problem.)

You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.

You cannot access the mountain array directly. You may only access the array using a MountainArray interface:

MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. 
Also, any solutions that attempt to circumvent the judge will result in disqualification.


Solution-
Nice question be cautious about edge cases (runtime error for sure).

we have to binary search 3 times.

1. find the peak element index;
2. binary search for finding target in "0 --> peak";
3. binary search for finding target in "peak + 1 --> n-1"


class Solution {
public:
    int findInMountainArray(int t, MountainArray &v) {
        int n = v.length();
        
        int l = 0, r = n-1;
        int peak = -1;

        while(l <= r){
            int mid = l + (r - l)/2;
            int b = v.get(mid);
            
            if((mid > 0) && b > v.get(mid-1) && (mid+1 < n) && b > v.get(mid+1)) {
                peak = mid;
                break;
            }
            // earlier i neglected edge case (mid == 0) here and got RTE, thinking that it would pass
            // without that

            if(mid == 0 || (v.get(mid-1) < b)){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }   

        l = 0, r = peak;

        while(l <= r){
            int mid = l + (r - l)/2;
            int val = v.get(mid);
            if(val == t) return mid;
            
            if(val < t) l = mid + 1;
            else r = mid - 1;
        }
        
        l = peak + 1; r = n-1;

        while(l <= r){
            int mid = l + (r - l)/2;
            int val = v.get(mid);
            if(val == t) return mid;
            
            if(val > t) l = mid + 1;
            else r = mid - 1;
        }
        
        return -1;
    }
};