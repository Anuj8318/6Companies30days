// 2461. Maximum Sum of Distinct Subarrays With Length K
// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/

#include<bits/stdc++.h>
usnig namespaces std;
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int left = 0, right = 0;
        long long maxisum = 0, sum = 0;
        int n = nums.size();
        
        while (right < n) {
            mp[nums[right]]++;
            sum += nums[right];
            
            // Shrink the window if its size exceeds k
            while ((right - left + 1) > k) {
                mp[nums[left]]--;
                if (mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }
                sum -= nums[left];
                left++;
            }
            
            // Check if the current window has exactly k distinct elements
            if ((right - left + 1) == k && mp.size() == k) {
                maxisum = max(maxisum, sum);
            }
            
            right++;
        }
        
        return maxisum;
    }
};
