Que-
Given an unsorted array Arr of size N of positive integers. One number 'A' from set 
{1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.


// marking visited elements as negative as all elements are positive
// as there is a repetition an element will be negative already as marked by prev same element
// we got the rep. ele, now for the missing no, the element at its index will be positive as we
// never visite that index.

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
       
       int ans[] = {-1, -1};
       for(int i = 0; i < n; i++) {
           int q = arr[abs(arr[i])-1];
           if(q < 0){
                ans[0] = abs(arr[i]);
           }
           else{
               arr[abs(arr[i])-1] *= -1;
           }
       }
       for(int i = 0; i < n; i++) {
            if(arr[i] > 0){
                ans[1] = i+1;
            }
       }
       int *d = ans;
       return d;
    }
};