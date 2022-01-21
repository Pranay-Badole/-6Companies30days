**Smallest range in K lists** 
GOOD QUESTION

// Given K sorted lists of integers, KSortedArray[] of size N each. The task is to find the smallest range that includes at least one element from each of the K lists.
// If more than one such ranges are found, return the first such range found.

// Input:
// N = 5, K = 3
// KSortedArray[][] = {{1 3 5 7 9},
//                     {0 2 4 6 8},
//                     {2 3 5 7 11}}
// Output: 1 2
// Explanation: K = 3

// A:[1 3 5 7 9]
// B:[0 2 4 6 8]
// C:[2 3 5 7 11]

// Smallest range is formed by number 1 present in first list and 2 is present in both 2nd and 3rd list.


Soln-
Same intuition as we do when "merging k sorted arrays", we will maintain a mih heap and at any time there will be exactly
k elements in the heap, if it goes less than k we will break, we will get the min element from the heap and for the max 
element we will use a varible "mx" to get the max element at any instance;

#################################################################################################################################################################################################################################

#define ppi pair<int, pair<int, int>> 

class comp{
public:
    bool operator() (ppi a, ppi b){
      return (a.first > b.first);
   }  
};

class Solution{
    public:
    pair<int,int> findSmallestRange(int v[][N], int n, int k)
    {
        priority_queue<ppi, vector<ppi>, comp> pq;
        
        int mx = -1;
        for(int i = 0; i < k; i++) {
            mx = max(mx, v[i][0]);
            pq.push({v[i][0],{i, 0}});
        }
        
        pair<int, int> ans = {-1, INT_MAX - 100};
        
        while(pq.size() >= k) {
            
            // cout << pq.top().first << ' ';
            
            int val = pq.top().first;
            int idx = pq.top().second.first;
            int pos = pq.top().second.second;
            pq.pop();
        
            if(ans.second - ans.first > mx - val){
                ans.first = val;
                ans.second = mx;
            }
                
            if(pos + 1 < n){
                mx = max(mx, v[idx][pos+1]);
                pq.push({v[idx][pos+1], {idx, pos + 1}});
            }
        }
        return ans;
    }
};