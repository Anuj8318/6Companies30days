
// 139. Word Break
// https://leetcode.com/problems/word-break/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true; // Base case: empty string can be segmented

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            string word = s.substr(j, i - j);
            if (dp[j] && wordSet.find(word) != wordSet.end()) {
                dp[i] = true;
                break; // No need to check further
            }
        }
    }

    return dp[n];   

    }
};