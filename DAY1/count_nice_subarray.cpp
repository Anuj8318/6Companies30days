//1248. Count Number of Nice Subarrays
//https://leetcode.com/problems/count-number-of-nice-subarrays/


#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
  int subString(vector<int>& nums, int goal) {
    if (goal < 0) return 0;
    int l = 0, r = 0, sum = 0, cnt = 0;
    while (r < nums.size()) {
        sum = sum+ nums[r] %2;
        while (sum > goal) {
            sum = sum - nums[l]%2;
            l++;
        }
        cnt += (r - l + 1);
        r++;
    }
    return cnt;
  }
public:

    int numberOfSubarrays(vector<int>& nums, int k) {

        // optimise approach
        int  num1 = subString(nums, k);
        int  num2 = subString(nums, k - 1);
        return num1 - num2;
    }
};
