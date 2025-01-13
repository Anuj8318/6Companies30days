//396. Rotate Function
// https://leetcode.com/problems/rotate-function/description/


class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
       int totalsum=0;
       int fun=0;
       for(int i =0;i<nums.size();i++)
       {
        totalsum+=nums[i];
        fun+=nums[i]*i;
       }
       int maxi =fun;
       for(int i =1;i<n;i++)
       {
         fun = fun + totalsum - n*nums[n-i];
         maxi = max(maxi,fun);
       }
       return maxi;
    }
};