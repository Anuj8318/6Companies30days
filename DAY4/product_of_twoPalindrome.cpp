//2002. Maximum Product of the Length of Two Palindromic Subsequences
// https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    
bool isPalindromic(const string &str) {
    int left = 0, right = str.size() - 1;
    while (left < right) {
        if (str[left] != str[right]) return false;
        left++;
        right--;
    }
    return true;
}

// Global variable to track the maximum product
int maxproduct = 0;

// Backtracking function
void backtrack(const string &s, int index, string subseq1, string subseq2) {
    if (index == s.size()) { // Base case: All characters are processed
        if (isPalindromic(subseq1) && isPalindromic(subseq2)) {
            maxproduct = max(maxproduct, (int)subseq1.size() * (int)subseq2.size());
        }
        return;
    }

    // Option 1: Add the current character to the first subsequence
    backtrack(s, index + 1, subseq1 + s[index], subseq2);

    // Option 2: Add the current character to the second subsequence
    backtrack(s, index + 1, subseq1, subseq2 + s[index]);

    // Option 3: Skip the current character
    backtrack(s, index + 1, subseq1, subseq2);
}
public:
    int maxProduct(string s) {
         maxproduct = 0; // Reset the global variable
    backtrack(s, 0, "", "");
    return maxproduct;
       




    }
};
