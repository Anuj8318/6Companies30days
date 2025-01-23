// 2572. Count the Number of Square-Free Subsets
// https://leetcode.com/problems/count-the-number-of-square-free-subsets/

// see it brute force before this 
class Solution {
public:
    const int MOD = 1e9 + 7;

    // Function for modular exponentiation: computes (base^exp) % MOD
    long long modExp(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int squareFreeSubsets(vector<int>& nums) {
        // Precomputed prime factors whose squares are <= 30
        vector<int> squareFreePrimes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

        // Mask of square-free primes for every number from 1 to 30
        vector<int> mask(31, 0);
        for (int i = 1; i <= 30; ++i) {
            for (int j = 0; j < squareFreePrimes.size(); ++j) {
                if (i % (squareFreePrimes[j] * squareFreePrimes[j]) == 0) {
                    mask[i] = -1; // Mark non-square-free numbers
                    break;
                }
                if (i % squareFreePrimes[j] == 0) {
                    mask[i] |= (1 << j);
                }
            }
        }

        // Count occurrences of each number in nums
        vector<int> count(31, 0);
        for (int num : nums) {
            ++count[num];
        }

        // DP to calculate square-free subsets
        vector<int> dp(1 << squareFreePrimes.size(), 0);
        dp[0] = 1; // Empty subset

        for (int i = 2; i <= 30; ++i) { // Start from 2 (skip 1 for now)
            if (count[i] == 0 || mask[i] == -1) continue;

            for (int state = (1 << squareFreePrimes.size()) - 1; state >= 0; --state) {
                if ((state & mask[i]) == mask[i]) {
                    dp[state] = (dp[state] + (long long)dp[state ^ mask[i]] * count[i]) % MOD;
                }
            }
        }

        // Handle the special case for number 1
        int ones = count[1];
        long long result = 0;
        for (int val : dp) {
            result = (result + val) % MOD;
        }

        // Multiply the total by the number of subsets formed by the 1s
        if (ones > 0) {
            result = (result * modExp(2, ones, MOD)) % MOD;
        }

        // Exclude the empty subset
        return (result - 1 + MOD) % MOD;
    }
};
