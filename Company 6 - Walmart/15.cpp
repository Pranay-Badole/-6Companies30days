**Divide Two Integers**

Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.


Solution-
if using long is allowed we can binary search the answer else Bit Manipulation.


class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == 1){
            return INT_MIN;
        }
        
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        
        long dvd = abs(dividend), dvs = abs(divisor);
        
        long l = 0, r = INT_MAX;
        int ans = 0;
        
        while(l <= r) {
            long mid = l + (r - l)/2;
            if((mid * dvs) <= dvd) {
                ans = mid;
                l = mid + 1;
            }
            else{
                 r = mid -1;
            }
        }
        return ans * sign;
    }
};