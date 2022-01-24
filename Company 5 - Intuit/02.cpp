Given a 2D board of letters and a word. Check if the word exists in the board. 
The word can be constructed from letters of adjacent cells only. ie - horizontal or vertical neighbors. 
The same letter cell can not be used more than once.


Soln-
STANDARD DFS SOLUTION
check for every index in the matrix if the word starting from that index can be potential answer

class Solution {
public:
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
        
    bool check(int i, int j, int c, vector<vector<char>> &v, string &word) {
        if(c >= word.size()) return 1;
        
        if(i < 0 || j < 0 || i >= v.size() || j >= v[0].size()){
            return 0;
        }
        if(v[i][j] != word[c]) {
            return 0;
        }

// instead of having a visited matrix to prevent a letter taking twice
// I would just change its value to some mark(here '%') so it wont satisfy the answer when we come back to this index again 
        
        char q = v[i][j];
        v[i][j] = '%';
        
        int ans = 0;
        for(int z = 0; z < 4; z++) {
            ans = check(i + dx[z], j + dy[z], c + 1, v, word);
            if(ans) return 1;
        }
        v[i][j] = q;
        return 0;
    }

    bool isWordExist(vector<vector<char>>& v, string word) {
        
        for(int i = 0; i < v.size(); i++) {
            for(int j = 0; j < v[0].size(); j++){
                int ans = check(i, j, 0, v, word);
                if(ans){return 1;}
            }
        }
        return 0;
    }
};