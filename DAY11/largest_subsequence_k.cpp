//2099. Find Subsequence of Length K With the Largest Sum
//https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/


class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq; // Max-heap
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i}); // Store value and index
        }

        vector<pair<int, int>> largest; // To store top k elements with indices
        while (k--) {
            largest.push_back(pq.top()); // Extract top element
            pq.pop();
        }

        // Sort the extracted elements by their original indices
        sort(largest.begin(), largest.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        });

        // Build the result subsequence
        vector<int> ans;
        for (auto& p : largest) {
            ans.push_back(p.first); // Push the value
        }

        return ans;
    }
};
