Que-

// Given an input stream of A of n characters consisting only of lower case alphabets.
// The task is to find the first non repeating character, each time a character is inserted to the stream.
// If there is no such character then append '#' to the answer.    

Soln-
// 2 pointers: left will point to the unrepeated character so far and i will be the last character
// added in the stream. to keep track of repeated characters we will use hash_map;

class Solution {
    public:
        string FirstNonRepeating(string s){
            unordered_map<char, int> mp;
            
            int n = s.size();
            
            int left = 0;
            string ans = "";
            
            for(int i = 0; i < n; i++) {
                mp[s[i]]++;
                int flag = 0;
                
                while(left <= i){
                    if(mp[s[left]] == 1){
                        flag = 1;
                        break;
                    }
                    left++;
                }
                if(flag == 0){
                    ans += '#';
                }
                else{
                    ans += s[left];
                }
            }
            return ans;
        }
};