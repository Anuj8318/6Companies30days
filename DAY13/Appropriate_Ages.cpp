// 825. Friends Of Appropriate Ages
// https://leetcode.com/problems/friends-of-appropriate-ages/

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end()); // Step 1: Sort the ages
        int totalRequests = 0;         // To store the total number of requests
        int n = ages.size();           // Number of persons

        for (int i = 0; i < n; i++) {
            // Skip invalid ages
            if (ages[i] <= 14) continue; // age[i] must be greater than 14 to send requests

            // Find the valid age range using two pointers
            int minAge = ages[i] / 2 + 7; // Lower bound: 0.5 * age[x] + 7
            int left = upper_bound(ages.begin(), ages.end(), minAge) - ages.begin(); // First valid index
            int right = upper_bound(ages.begin(), ages.end(), ages[i]) - ages.begin(); // Last valid index + 1

            // Add the count of valid people in the range
            totalRequests += right - left - 1; // Subtract 1 to exclude self-pairing
        }

        return totalRequests;
    } 
};