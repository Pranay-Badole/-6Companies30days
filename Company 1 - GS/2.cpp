// Que-
// Given two rectangles, find if the given two rectangles overlap or not. 
// A rectangle is denoted by providing the x and y coordinates of two points: 
// the left top corner and the right bottom corner of the rectangle. 
// Two rectangles sharing a side are considered overlapping. 
// (L1 and R1 are the extreme points of the first rectangle and L2 and R2 are the extreme points of the second rectangle).

// Note: It may be assumed that the rectangles are parallel to the coordinate axis.

//       l<------>r
//        ________  u
//       |        | |
//       |        | |
//       |________| d


class Solution {
  public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        
        int l1 = L1[0];int r1 = R1[0];int d1 = R1[1];int u1 = L1[1];
        int l2 = L2[0];int r2 = R2[0];int d2 = R2[1];int u2 = L2[1];
        
        if((r1 < l2) || (r2 < l1)) return 0;
        if((u1 < d2) || (u2 < d1)) return 0;
        
        return 1;
    }
};