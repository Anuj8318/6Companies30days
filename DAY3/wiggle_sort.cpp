// 324. Wiggle Sort II
// https://leetcode.com/problems/wiggle-sort-ii/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
       vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        int n = nums.size();

        int mid = (n - 1) / 2; 
    
        int end = n - 1;       
        int i = 0;
        while (i < n) {
            if (i % 2 == 0) {
                nums[i++] = arr[mid--]; 
            } else {
                nums[i++] = arr[end--]; 
            }
        }
    }
};
