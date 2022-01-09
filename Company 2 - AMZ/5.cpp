Que-
// Given a list of contacts contact[] of length n where each contact is a string which exist in a phone directory and aquery string s. 
// The task is to implement a search query for the phone directory. Run a search query for each prefix p of the query string s 
// (i.e. from  index 1 to |s|) that prints all the distinct contacts which have the same prefix as p in lexicographical increasing order. 
// Please refer the explanation part for better understanding.
// Note: If there is no match between query and contacts, print "0".



// Standard Trie DS problem
// one can also try it with hashmaps

class Trie{
public:
    bool word = false;  
    Trie* next[26]; 
    // as it contains only lowercase letters we use array of size of 26 otherwise use 
    // unordered_map<char, Trie*>next;

    Trie(){
        word = false;
        for(int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
};

class Solution{
public:

   void insert(Trie* head, string &s) {
        
        for(int i = 0; i < s.size(); i++) {
            int t = (int)(s[i] - 'a');
            if(head -> next[t] == NULL){
                head -> next[t] = new Trie();
            }
            head = head -> next[t];
        }
        head -> word = true;
    }
    
    void get_all(Trie *head, string &s, vector<string> &ans) {
    
        if(head == NULL) return;
        if(head -> word == 1){ans.push_back(s);}
        
        for(int i = 0; i < 26; i++) {
            char c = (char)('a' + i);
            s.push_back(c);
            get_all(head -> next[i], s, ans);
            s.pop_back();
        }
    }
    
    vector<string> find_tail(Trie* head, string &s){
        vector<string> ans;
        for(int i = 0; i < s.size(); i++){
            int t = (int)(s[i] - 'a');
            if(head -> next[t] == NULL){
                return ans;
            }
            head = head -> next[t];
        }
        string t = s;
        get_all(head, t, ans);
        return ans;
    }
    
    vector<vector<string>> displayContacts(int n, string v[], string s)
    {
        Trie *head = new Trie();
        
        for(int i = 0; i < n; i++) {
            
            insert(head, v[i]);
        }
        vector<vector<string>> res;
        
        for(int i = 0; i < s.size(); i++){
            string t = s.substr(0, i+1);
            vector<string> temp = find_tail(head, t);
            if(!temp.size()) {
                temp.push_back("0");
            }
            res.push_back(temp);
        }
        // string t = "";
        // vector<string> ans;
        // get_all(head, t, ans);
        // for(auto x : ans) cout << x << ' ';
        
        return res;
    }
};