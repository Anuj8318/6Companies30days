// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
private:
    vector<string> result;
    string current;
    vector<string> digitToLetters = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(const string& digits, int index) {
        // Base case: if we've processed all digits
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        // Get the letters corresponding to the current digit
        string letters = digitToLetters[digits[index] - '0'];

        // Iterate over each letter and backtrack
        for (char letter : letters) {
            current.push_back(letter); // Choose
            backtrack(digits, index + 1); // Explore
            current.pop_back(); // Unchoose
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; // Edge case: empty input
        result.clear();
        current = "";
        backtrack(digits, 0);
        return result;
    }
};
