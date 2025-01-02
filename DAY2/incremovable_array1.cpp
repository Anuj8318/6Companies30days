//2970. Count the Number of Incremovable Subarrays I
//https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/   
#include<bits/stdc++.h>
using namespace std;

class Solution {
bool check(vector<int>& nums)
{
    for(int i =1;i<nums.size();i++)
    {
        if(nums[i]<=nums[i-1])
        {
            return false;
        }
    }
    return true;
}
public:
    int incremovableSubarrayCount(vector<int>& nums) {
       int count=0;
       for(int i =0;i<nums.size();i++)
       {
         for(int j = i;j<nums.size();j++)
         {
           vector<int>arr;
           for(int k =0;k<nums.size();k++)
           {
             if(k==i)
             {
                k = j;
                continue;
             }
            //  cout<<nums[k]<<" ";
             arr.push_back(nums[k]);
           }
        //    cout<<endl;
            if(check(arr))
            {
                count++;
            }
         }
       }   
       return count;
    }
};