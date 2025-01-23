// 2261. K Divisible Elements Subarrays
// https://leetcode.com/problems/k-divisible-elements-subarrays/
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
     map<vector<int>,int>mp;
     for(int i =0;i<nums.size();i++)
     {
        int count=0;
        // vector<int>arr;
        for(int j =i;j<nums.size();j++)
        {
            if(nums[j]%p==0 && count<=k)
            {
                count++;
            }
            if(count<=k)
            {
                vector<int>arr;
                for(int k=i;k<=j;k++)
                {
                 arr.push_back(nums[k]);
                }
                mp[arr]++;
            }
        }
     }   
     return mp.size();
    }
};