Que-
// Given a pattern containing only I's and D's. I for increasing and D for decreasing.
// Devise an algorithm to print the minimum number following that pattern.
// Digits from 1-9 and digits can't repeat.



Soln -
// if current element is 'I' 
//         : the next is not 'D' print MEX(minimum excluding element starting from 1) and do MEX++
//         : the next is 'D' we will cnt the consecutive 'DD...' following the current element and value of current 
//              index will be MEX + cnt and the following D's will be MEX - 1, MEX -2, MEX - 3.......

// we will never get 'D' as current element as we pass it while counting consecutive D's in above process.



class Solution{   
public:
    string printMinNumberForPattern(string s){
        int cur = 1;
        int l = 0;
        s = '*' + s;

        int n = s.size();
        string ans = "";
        
        while(l < n) {
            if((l + 1 < n) && (s[l + 1] == 'D')) {
                l++;
                int cnt = 0;
                while(l < n && s[l] == 'D'){
                    l++;
                    cnt++;
                }
                cur += cnt;
                ans += (char)('0' + cur);
                int z = cur - 1;
                while(cnt--){
                    ans += (char)('0' + z);
                    z--;
                }
                cur++;
            }
            else{
                ans += (char)('0' + cur);
                cur++;
                l++;
            }
        }
        return ans;
    }
};