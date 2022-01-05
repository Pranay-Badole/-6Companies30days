Que-

// An encoded string (s) is given, the task is to decode it. The pattern in which the strings were encoded were as follows
// original string: abbbababbbababbbab 
// encoded string : 3[a3[b]1[ab]]


class Solution{
public:
    
    int mp[31];
    
    string fun(int i, string &s) {
        int n = s.size();
        if(i >= n) return "";
        
        string ans = ""; 
        
        while(isalpha(s[i])) ans += s[i++];
        int next = i;
        while(isdigit(s[next])) {next++;}
        
        if(s[i] == ']') return ans;
        
        int mul = stoi(s.substr(i, next - i));
        string temp = fun(next + 1, s);
        while(mul--){
            ans += temp;
        }
        
        ans += fun(mp[next] + 1, s);
    
        return ans;
    }
    
    string decodedString(string s){
        memset(mp, -1, sizeof mp);
        string ans = "";
        int n = s.size();
        
        stack<int> st;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '[') st.push(i);
            if(s[i] == ']') {
                int j = st.top();
                st.pop();
                mp[i] = j;
                mp[j] = i;
            }
        }
        // for(int i = 0; i < n; i++) cout << mp[i] << ' ';
        ans = fun(0, s);
        return ans;
    }
};