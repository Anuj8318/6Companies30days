// 2707. Extra Characters in a String
// https://leetcode.com/problems/extra-characters-in-a-string/




class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
       int n = s.length();
       unordered_set<string>dict(dictionary.begin(), dictionary.end());
       vector<int>dp(n+1,n);
       dp[0] =0;
       for(int i =1;i<=n;i++)
       {
        for(int j =0;j<i;j++)
        {
         string substring = s.substr(j,i-j);
         if(dict.count(substring))
         {
            dp[i] = min(dp[i],dp[j]);
         }
         else
         {
            dp[i] = min(dp[i],dp[j]+(i-j));
         }
        }
       } 
       return dp[n];
    }
};