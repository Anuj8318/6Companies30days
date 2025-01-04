//497. Random Point in Non-overlapping Rectangles
//https://leetcode.com/problems/random-point-in-non-overlapping-rectangles
#include<bits/stdc++.h>
using namespace std;


class Solution {
    vector<vector<int>> rects;
    vector<int> areas;
    int totalArea = 0;

public:
    Solution(vector<vector<int>>& rects) : rects(rects) {
        for (const auto& rect : rects) {
            int area = (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            totalArea += area;
            areas.push_back(totalArea); // Cumulative sum of areas
        }
    }

    vector<int> pick() {
        int randomPoint = rand() % totalArea; // Pick a random point in the total area
        int rectIndex = lower_bound(areas.begin(), areas.end(), randomPoint + 1) - areas.begin();

        // Extract the rectangle
        auto& rect = rects[rectIndex];
        int x = rect[0] + rand() % (rect[2] - rect[0] + 1);
        int y = rect[1] + rand() % (rect[3] - rect[1] + 1);

        return {x, y};
    }
};

