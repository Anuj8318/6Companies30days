//845. Longest Mountain in Array
//https://leetcode.com/problems/longest-mountain-in-array/

class Solution {
public:
    int longestMountain(vector<int>& arr) {
    int n = arr.size();
    if (n < 3) return 0; // A mountain requires at least 3 elements

    int longest = 0;
    int i = 1; // Start from the second element

    while (i < n - 1) {
        // Check if `i` is a peak
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
            int left = i - 1;
            int right = i + 1;

            // Expand to the left
            while (left > 0 && arr[left - 1] < arr[left]) {
                left--;
            }

            // Expand to the right
            while (right < n - 1 && arr[right] > arr[right + 1]) {
                right++;
            }

            // Calculate the length of the mountain
            longest = max(longest, right - left + 1);

            // Move `i` to the end of the current mountain
            i = right;
        } else {
            // Move to the next element
            i++;
        }
    }

    return longest;
}

    
};