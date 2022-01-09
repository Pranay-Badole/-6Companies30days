Que-
// Check if sudoku is valid


// dont know why getting TLE in GFG but passed in leetcode, 
// happened with many others as well (read comments).

class Solution{
public:
    int isValid(vector<vector<int>> v){
        
        // check for every row
        for(int i = 0; i < 9; i++) {
            unordered_set<int> st;
            for(int j = 0; j < 9; j++) {
                int t = v[i][j];
                if(st.count(t)){
                    return 0;
                }
                if(t != 0){
                    st.insert(t);
                }
            }
        }

        // check for every column
        for(int j = 0; j < 9; j++) {
            unordered_set<int> st;
            for(int i = 0; i < 9; i++) {
                int t = v[i][j];
                if(st.count(t)){
                    return 0;
                }
                if(t != 0){
                    st.insert(t);
                }
            }
        }
        
        // check for every 3x3 boxes (0,0) (0,3) (0,6) (3,0) (3,3).......
        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                unordered_set<int> st;
                
                for(int a = 0; a < 3; a++) {
                    for(int b = 0; b < 3; b++) {
                        int t = v[i+a][j+b];
                        
                        if(st.count(t)){
                            return 0;
                        }
                        if(t != 0){
                            st.insert(t);
                        }
                    }
                }
            }
        }
        return 1;
    }
};