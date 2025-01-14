// 718. Maximum Length of Repeated Subarray
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
     int n = nums1.size();
        int m = nums2.size();
        
        // DP table to store lengths of common subarrays
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int maxi = 0;  // Maximum length of common subarray
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;  // Extend previous subarray
                    maxi = max(maxi, dp[i][j]);      // Update maximum length
                }
            }
        }
        return maxi;
    }
};