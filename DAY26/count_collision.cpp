// 2211. Count Collisions on a Road
// https://leetcode.com/problems/count-collisions-on-a-road/
class Solution {
public:
    int countCollisions(string directions) {
       int right = 0, res = 0, obstacle = false;
    for (char d : directions)
        if (d == 'R')
            ++right;
        else if (d == 'S') {
            res += right;
            right = 0;
            obstacle = true;
        }
        else {
            if (right > 0) {
                res += right + 1;
                right = 0;
                obstacle = true;
            }
            else if (obstacle)
                ++res;
        }
    return res; 
    }
};