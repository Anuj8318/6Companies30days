// 1401. Circle and Rectangle Overlapping
// https://leetcode.com/problems/circle-and-rectangle-overlapping/


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find the closest point on the rectangle to the circle's center
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));
        
        // Compute the distance from the circle's center to this closest point
        int dx = closestX - xCenter;
        int dy = closestY - yCenter;
        
        // Check if this distance is less than or equal to the circle's radius
        return (dx * dx + dy * dy) <= (radius * radius);
    }
};


