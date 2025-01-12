// 368. Largest Divisible Subset
// https://leetcode.com/problems/largest-divisible-subset/


#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<vector<int>>> dp; // Memoization table

    vector<int> findSubset(int ind, int prevInd, vector<int>& nums) {
        if (ind == nums.size()) return {}; // Base case: End of array

        if (!dp[ind][prevInd + 1].empty()) 
            return dp[ind][prevInd + 1]; // Use memoized result if available

        // Exclude current element
        vector<int> exclude = findSubset(ind + 1, prevInd, nums);

        // Include current element (if valid)
        vector<int> include;
        if (prevInd == -1 || nums[ind] % nums[prevInd] == 0) {
            include = findSubset(ind + 1, ind, nums);
            include.push_back(nums[ind]);
        }

        // Return and memoize the larger subset
        return dp[ind][prevInd + 1] = (include.size() > exclude.size() ? include : exclude);
    }

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sorting ensures divisibility property
        int n = nums.size();
        dp.resize(n, vector<vector<int>>(n + 1)); // Initialize dp table
        vector<int> result = findSubset(0, -1, nums);
        reverse(result.begin(), result.end()); // Reverse the subset for ascending order
        return result;
    }
};
