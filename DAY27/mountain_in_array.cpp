// 1095. Find in Mountain Array
// https://leetcode.com/problems/find-in-mountain-array/
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:

 int getPivot(MountainArray& mountainArr)
 {
     int low = 1;
     int high = mountainArr.length()-2;
     while(low!=high)
     {
        int mid  = (low+high)/2;
        if(mountainArr.get(mid)<mountainArr.get(mid+1))
        {
            low = mid+1;
        }
        else
        {
            high = mid;
        }
     }
     return low;
 }

//  left part
 int binary_first(MountainArray& mountainArr, int target,int low, int high)
 {
    while(low!=high)
    {
         int mid = (low+high)/2;
        if(mountainArr.get(mid)==target)
        {
           return mid;
        }
        if(mountainArr.get(mid)<target)
        {
            low = mid+1;
        }
        else
        {
            high = mid;
        }
    }
    if(mountainArr.get(low)==target)
    {
        return low;
    }
    return -1;
 }

// right part
 int binary_second(MountainArray& mountainArr, int target,int low, int high)
 {
     while (low < high) {
        int mid = (low + high) / 2;
        if (mountainArr.get(mid) == target) {
            return mid;
        }
        if (mountainArr.get(mid) > target) {
            low = mid + 1;  
        } else {
            high = mid;   
        }
    }
    if (mountainArr.get(low) == target) {
        return low;
    }
    return -1;
 }


public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int length = mountainArr.length();
    int peakIndex = getPivot(mountainArr);  
    int ans1 = binary_first(mountainArr, target, 0, peakIndex);  
    if (ans1 != -1) {
        return ans1;  
    }
    int ans2 = binary_second(mountainArr, target, peakIndex + 1, length - 1);  
     return ans2;
    }
};