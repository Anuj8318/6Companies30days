
// 2233. Maximum Product After K Increments
// https://leetcode.com/problems/maximum-product-after-k-increments/

class Solution {
int MOD = 1e9+7;
public:
    int maximumProduct(vector<int>& nums, int k) {
        
        priority_queue<int,vector<int>,greater<int>>minheap;
        for(auto it:nums)
        {
            minheap.push(it);
        }
        while (k--) {
            int top = minheap.top();
            minheap.pop();
            minheap.push(top + 1);
        }

        // Compute the product modulo MOD
        long long ans = 1;
        while (!minheap.empty()) {
            ans = (ans * minheap.top()) % MOD;
            minheap.pop();
        }

        return ans;
    }
};