Que- Given an infinite number line. You start at 0 and can go either to the left or to the right. 
The condition is that in the ith move, youmust take i steps. Given a destination D , find the minimum 
number of steps required to reach that destination.

Soln-
Good question the solution isnt that much complex but the it requires analyzing what will be the 
answer for small test cases like i did for small numbers from 1-7 and got that we will keep adding 
till the sum is >= D. 
    : if it is == D, then the last no added will be the answer
    : if it is > D, 
        =>  then we will check if the difference between them is even or not because 
            to reduce the sum we will need number = "diff / 2"  to subtract from it and it is only 
            possible in even case.
        => if odd, increment further till the dif is even.


class Solution{
public:
    int minSteps(int D){
        if(D < 0) D *= -1;
        int sum = 0;
        int i = 1;
        
        while(1){
            sum += i;    
            if(sum == D) break;
            if(sum > D && (sum - D)%2 == 0) break;
            i++;
        }
        return i;
    }
};