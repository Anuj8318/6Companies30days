// 451. Sort Characters By Frequency
// https://leetcode.com/problems/sort-characters-by-frequency/

class Solution {
public:
    string frequencySort(string s) {
     // Count the frequency of each character in the string
    unordered_map<char, int> charCount;
    for (char c : s) {
        charCount[c]++;
    }

    // Create a vector of pairs to store characters and their frequencies
    vector<pair<char, int>> charFreqVec(charCount.begin(), charCount.end());

    // Sort the vector based on frequency in descending order
    sort(charFreqVec.begin(), charFreqVec.end(),
         [](const pair<char, int>& a, const pair<char, int>& b) {
             return a.second > b.second;
         });

    // Build the sorted string by repeating each character according to its frequency
    string result;
    for (const auto& entry : charFreqVec) {
        result += string(entry.second, entry.first);
    }

    return result;
        
    }
};