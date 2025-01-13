// 532. K-diff Pairs in an Array
// https://leetcode.com/problems/k-diff-pairs-in-an-array/


class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0; // Absolute difference cannot be negative
        unordered_map<int, int> freq;
        int count = 0;

        // Count the frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        for (auto& [num, freq_count] : freq) {
            if (k == 0) {
                // For k = 0, we count elements that appear more than once
                if (freq_count > 1) {
                    count++;
                }
            } else {
                // For k > 0, check if the counterpart (num + k) exists
                if (freq.find(num + k) != freq.end()) {
                    count++;
                }
            }
        }
        return count;
    }
};
