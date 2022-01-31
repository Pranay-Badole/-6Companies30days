**Find the Kth Largest Integer in the Array**

Que-
You are given an array of strings nums and an integer k. Each string in nums represents an integer without leading zeros.

Return the string that represents the kth largest integer in nums.

Note: Duplicate numbers should be counted distinctly. 
For example, if nums is ["1","2","2"], "2" is the first largest integer, 
"2" is the second-largest integer, and "1" is the third-largest integer.


Solution-
Here you will be introduced to how to make the custom comparator function for heap (priority_queue in c++ STL)

As the string length can be upto 100 we cant represent it in terms of even 64 bit integer
so we will make heap of strings and add our own comparator function.


class Solution {
public:
    
    class cmp{
        public:
            bool operator()(string a, string b) {
                if(a.size() < b.size()) {
                    return 0;
                }
                else if(a.size() > b.size()){
                    return 1;
                }
                int n = a.size();
                for(int i = 0; i < n; i++) {
                    if(a[i] < b[i]){
                        return 0;
                    }
                    else if(a[i] > b[i]){
                        return 1;
                    }
                }
                return 0;
            }
    };
    
    string kthLargestNumber(vector<string>& nums, int k) {
        
        priority_queue<string, vector<string>, cmp> pq;
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            if(pq.size() > k){pq.pop();}
        }
        
        return pq.top();
    }
    
};