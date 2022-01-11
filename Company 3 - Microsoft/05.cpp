The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stock’s price for all n days. 
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.


Soln- This question boils down to finding the prev_max element of and element
this can be done using stack to get the index of pre_max (standard stack problem)



class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int v[], int n)
    {
       stack<int> st;
       vector<int> prev_mx(n, 0);
       
       for(int i = 0; i < n; i++) {
           							
           while(st.size() && v[st.top()] <= v[i]){ 
           				   // v[st.top()] "<"" v[i] if we want to find the prev equal or max
               st.pop();
           }
           if(st.size()){
               prev_mx[i] = st.top();
           }
           else prev_mx[i] = -1;
           
           st.push(i);
       }
      for(int i = 0; i < n; i++) {
          prev_mx[i] = i - prev_mx[i];
      }
       
       return prev_mx;
    }
};