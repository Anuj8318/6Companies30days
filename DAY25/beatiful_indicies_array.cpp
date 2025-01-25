// 3006. Find Beautiful Indices in the Given Array I
// https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-i/
class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
    vector<int> beautifulIndices;
    vector<int> indicesA;
    vector<int> indicesB;

    // Ensure s is long enough for a and b
    if (s.length() < a.length() || s.length() < b.length()) {
        return beautifulIndices; // Return an empty vector as no matches are possible
    }

    // Find all starting indices where substring `a` matches in `s`
    for (int i = 0; i <= s.length() - a.length(); ++i) {
        if (s.substr(i, a.length()) == a) {
            indicesA.push_back(i);
        }
    }

    // Find all starting indices where substring `b` matches in `s`
    for (int j = 0; j <= s.length() - b.length(); ++j) {
        if (s.substr(j, b.length()) == b) {
            indicesB.push_back(j);
        }
    }

    // Check for each index in indicesA if there exists a valid index in indicesB
    for (int i : indicesA) {
        for (int j : indicesB) {
            if (abs(j - i) <= k) {
                beautifulIndices.push_back(i);
                break; // No need to check further for this `i`, move to the next
            }
        }
    }

    return beautifulIndices;
    }
};