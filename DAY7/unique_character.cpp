
// 387. First Unique Character in a String
// https://leetcode.com/problems/first-unique-character-in-a-string/

#include<bit/stdc++.h>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> counting;
        
        // First pass to count occurrences of each character
        for (char c : s) {
            counting[c]++;
        }
        
        // Second pass to find the first unique character
        for (int i = 0; i < s.length(); i++) {
            if (counting[s[i]] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};
