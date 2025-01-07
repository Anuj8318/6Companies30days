// K Sized Subarray Maximum
// https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1



class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
       vector<int> ans;
    deque<int> dq; 

    for (int i = 0; i < arr.size(); ++i) {
        // Remove indices that are out of the current window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // Remove indices of all elements smaller than the current element
        // as they are not useful
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

        // Add the current element's index to the deque
        dq.push_back(i);

        // Add the maximum element of the current window to the result
        if (i >= k - 1) {
            ans.push_back(arr[dq.front()]);
        }
    }

    return ans;
    }
};