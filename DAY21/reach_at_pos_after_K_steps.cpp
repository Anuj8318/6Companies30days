// 2400. Number of Ways to Reach a Position After Exactly k Steps
// https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k

class Solution {
private:
    const int MOD = 1e9 + 7;

    int fun(int st, int en, int k, vector<vector<int>>& dp, int offset) {
        if (k == 0) {
            return st == en ? 1 : 0; // Base case: no steps left, check if positions match
        }
        if (dp[st + offset][k] != -1) return dp[st + offset][k]; // Use memoized result
        
        // Recursive calls for left and right moves
        int left = fun(st - 1, en, k - 1, dp, offset) % MOD;
        int right = fun(st + 1, en, k - 1, dp, offset) % MOD;
        
        return dp[st + offset][k] = (left + right) % MOD; // Store result modulo MOD
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        int maxOffset = 1000 + k; // Offset to handle all valid positions
        vector<vector<int>> dp(2 * maxOffset + 1, vector<int>(k + 1, -1)); // Initialize DP array
        
        return fun(startPos, endPos, k, dp, maxOffset);
    }
};
