//462. Minimum Moves to Equal Array Elements II
//https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
      int count=0;
      int n = nums.size();
      sort(nums.begin(), nums.end());
      int mid =  (0+n)/2;
      int ele = nums[mid];
      for(int i =0;i<n;i++)
      {
        count+=abs(nums[i]-ele);
      }
      return count;
    }
};