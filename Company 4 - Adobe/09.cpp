**Next higher palindromic number using the same set of digits**
Given a palindromic number N in the form of string. The task is to find the smallest palindromic 
number greater than N using the same set of digits as in N.



Soln -

Just an extension of "finding next greater number from the same set of digits".
take first half of the string apply the algo of the above problem on it.
if we cant get next highest number return -1;

if the original string is odd in size, make sure to add the middle char in the ans;

let the next higher string which we get is "t";
then

    ans = t + middle_char(if odd) + reverse(t);

class Solution{
  public:
    string nextPalin(string s) { 
        string t = "";
        int n = s.size();
        
        for(int i = 0; i < n/2; i++)  t += s[i];
        
        char c;
        if(n & 1) c = s[n/2]; 
        
        int r = t.size() - 2;
        
        while(r >= 0){
            if(t[r] < t[r+1]){

                int j = r + 1;
                while(j < t.size() && t[j] > t[r]) {
                    j++;
                }
                swap(t[r], t[j-1]);
                break;
            }
            r--;
        }

        if(r < 0) return "-1";
        reverse(t.begin() + r + 1, t.end());

        string ans = t;

        if(n & 1) t += c;
        
        reverse(t.begin(), t.end());
        ans += t;
        
        return ans;
    }
};