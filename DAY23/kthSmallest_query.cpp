// 2343. Query Kth Smallest Trimmed Number
// https://leetcode.com/problems/query-kth-smallest-trimmed-number/
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        // copyting this operator 
       vector<int> ans;
        for (const auto& query : queries) {
            int k = query[0];
            int trim = query[1];

            vector<pair<string, int>> trimmedNums;
            for (int i = 0; i < nums.size(); ++i) {
                int len = nums[i].length();
                string trimmed = nums[i].substr(len - trim);
                trimmedNums.push_back({trimmed, i});
            }

            sort(trimmedNums.begin(), trimmedNums.end());

            ans.push_back(trimmedNums[k - 1].second);
        }
        return ans;
    }
};