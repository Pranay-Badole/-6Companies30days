**Leaders in an array**

Que- 
Given an array A of positive integers. Your task is to find the leaders in the array. An element of array is leader if it is 
greater than or equal to all the elements to its right side. The rightmost element is always a leader. 


Soln- Traverse the array in reverse and maintain a variable mx which will, basically for an index i, 
store the maximum of all the numbers from i + 1 -> n.

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        vector<int> ans;
        int mx = -1;
        for(int i = n-1; i >= 0; i--) {
            if(a[i] >= mx){
                ans.push_back(a[i]);
            }
            mx = max(mx, a[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};