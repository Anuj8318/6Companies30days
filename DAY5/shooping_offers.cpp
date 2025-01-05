// 638. Shopping Offers
// https://leetcode.com/problems/shopping-offers/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<string, int> memo;
        return shopping(price, special, needs, memo);
    }

private:
    int shopping(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, unordered_map<string, int>& memo) {
        string key = encode(needs);
        if (memo.count(key)) return memo[key];

        int res = dot(needs, price); // Calculate the cost without any offers

        for (auto& s : special) {
            vector<int> clone = needs;
            int j = 0;
            for (; j < needs.size(); j++) {
                int diff = clone[j] - s[j];
                if (diff < 0) break; // If any item in the special exceeds the need, break
                clone[j] = diff;
            }
            // If the special offer is valid for the current needs
            if (j == needs.size()) {
                res = min(res, s[j] + shopping(price, special, clone, memo));
            }
        }

        memo[key] = res;
        return res;
    }

    int dot(vector<int>& a, vector<int>& b) {
        int sum = 0;
        for (int i = 0; i < a.size(); i++) {
            sum += a[i] * b[i];
        }
        return sum;
    }

    string encode(vector<int>& needs) {
        string key;
        for (int n : needs) {
            key += to_string(n) + ",";
        }
        return key;
    }
};
