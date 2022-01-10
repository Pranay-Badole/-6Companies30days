Que -

Brackets in Matrix Chain Multiplication


// we need to get the result from matrix chain multiplication to form the brackets
// that is for a particular range l <--> r whats the optimum i (l <--> r-1) and we will use  

***THE TOUGHEST ONE SO FAR***

class Solution{
public:
    int bra[27][27];
    int dp[27][27];
    
    int fun(int l, int r, int *v) {

        if(l >= r) return 0;
        
        if(dp[l][r] != -1) return dp[l][r];
        int ans = INT_MAX;
        
        for(int i = l; i < r; i++) {
            int fr = fun(l, i, v);
            int sc = fun(i+1, r, v);
         
            int temp = fr + sc + (v[l] * v[i+1] * v[r+1]);
            if(temp < ans) {
                ans = temp;
                bra[l][r] = i;
            }
        }
        
        return dp[l][r] = ans;
    }

string form(int i, int j, char &c){
    
    if(i == j){
        string t = "";
        t += c;
        c++;
        return t;
        
    }
    else{
        string t = "(";
        t += form(i, bra[i][j], c);
        t += form(bra[i][j]+1, j, c);
        t += ")";
        
        return t;
    }
}

    string matrixChainOrder(int v[], int n){
        memset(bra, 0, sizeof bra);
        memset(dp, -1, sizeof dp);
        
        string res = "";
        int ans = fun(0, n-2, v);
        
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         cout << bra[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        
        char c = 'A';
        res = form(0, n - 2, c);

        return res;
    }
};