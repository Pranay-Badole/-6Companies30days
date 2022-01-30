**Generate Random Point in a Circle**

Que-
Given the radius and the position of the center of a circle, implement the function randPoint which generates a uniform random point inside the circle.

Implement the Solution class:

Solution(double radius, double x_center, double y_center) initializes the object with the radius of the circle radius
and the position of the center (x_center, y_center).

randPoint() returns a random point inside the circle. A point on the circumference of the circle is considered to be in the circle. 
The answer is returned as an array [x, y].

Solution:
Randomization with ensuring uniformity.

See,
Area of circle with radius r = pi * (r*r);
Area of circle with radius 2r = pi * (2r*2r);
Area of circle with radius 3r = pi * (3r*3r);

it is in the ratio
1A : 4A : 9A : . . . . .

if we take segments each of radius r;
it is in the ratio

1A : (4A - 1A) : (9A - 4A) : . . . . .

1 : 3 : 5

as the area of segments keep on increasing, the no of points on it should also keep on increasing.
so random() wont work as it would assign equally to each segment.

so suppose we get 0.90 in random we will try assign it to greater segment 
so we can just use sqrt(0.90) = 0.948

So, 
for radius ==> sqrt(rand());
for angle ==> rand();




class Solution {
public:
    double rad, x_cen, y_cen;
    
    Solution(double radius, double x_center, double y_center) {
        rad = radius;
        x_cen = x_center;
        y_cen = y_center;
        srand(time(0));
    }
    
    
    vector<double> randPoint() {
        vector<double> ans;
        
        double r = sqrt(((double)rand()) / RAND_MAX);
        r *= rad;
     
        double degree = ((double)rand() / RAND_MAX); 
        degree *= 360;
        
        
        double x = r * sin((1.0*degree*22)/(7 * 180));
        double y = r * cos((1.0*degree*22)/(7 * 180));
        
        // cout << r << ' ' << degree <<  endl;
        x += x_cen;
        y += y_cen;
        ans = {x, y};
        
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */