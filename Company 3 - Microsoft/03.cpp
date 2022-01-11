Que- Given a square matrix[][] of size N x N. The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space.


Soln-
rotating it by 90 is similar to ==>

1. swapping elements wrt to the diagonal 

1 2 3   swapping  \       1 4 7       
4 5 6     wrt      \      2 5 8       
7 8 9  diagonal     \     3 6 9       

2. swapping along the middle X-axis

1 4 7    swapping                   3 6 9
2 5 8   wrt middle       ------     2 5 8
3 6 9     X-axis                    1 4 7

// we can also do it using nested loops but that's a little complicated and thus hectic.

void rotate(int n, int a[][n])
{
    //#1
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int t = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = t;
            // swap(a[i][j], a[j][i]);
        }
    }
    //#2
    for(int i = 0; i < n/2; i++) {
        for(int j = 0; j < n; j++) {
            int t = a[i][j];
            a[i][j] = a[n-1-i][j];
            a[n-1-i][j] = t;
        }
    }
}