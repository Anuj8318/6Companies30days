// 661. Image Smoother
// https://leetcode.com/problems/image-smoother/
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();  
        int n = img[0].size();   
        vector<vector<int>> result(m, vector<int>(n, 0));

        // Direction vectors for neighbors in a 3x3 grid
        vector<int> dx = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                long long sum = 0; 
                int count = 0;
                for (int k = 0; k < 9; ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        sum += img[ni][nj];
                        ++count;
                    }
                }
                result[i][j] = floor(sum / count); 
            }
        }

        return result;
    }
};