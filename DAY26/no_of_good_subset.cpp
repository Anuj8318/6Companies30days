// 1994. The Number of Good Subsets
// https://leetcode.com/problems/the-number-of-good-subsets/
class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        const int MOD = 1e9 + 7;

        // All prime numbers <= 30
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

        // Map each number to a bitmask of primes (0 means non-valid)
        unordered_map<int, int> numToMask;
        for (int num = 2; num <= 30; ++num) {
            int mask = 0, x = num;
            bool isValid = true;
            for (int i = 0; i < primes.size(); ++i) {
                int prime = primes[i], count = 0;
                while (x % prime == 0) {
                    x /= prime;
                    count++;
                }
                if (count > 1) { // Not valid as it has square of a prime
                    isValid = false;
                    break;
                }
                if (count == 1) mask |= (1 << i);
            }
            if (isValid) numToMask[num] = mask;
        }

        // Frequency of numbers in nums
        vector<int> freq(31, 0);
        for (int num : nums) freq[num]++;

        // DP array to count subsets
        vector<int> dp(1 << primes.size(), 0);
        dp[0] = 1; // Base case: empty subset

        for (int num = 2; num <= 30; ++num) {
            if (freq[num] == 0 || numToMask.count(num) == 0) continue;
            int mask = numToMask[num];

            // Update DP from back to front to avoid overwriting
            for (int state = (1 << primes.size()) - 1; state >= 0; --state) {
                if ((state & mask) == 0) { // No conflict
                    dp[state | mask] = (dp[state | mask] + (long long)dp[state] * freq[num]) % MOD;
                }
            }
        }

        // Calculate the result
        int result = 0;
        for (int state = 1; state < (1 << primes.size()); ++state) {
            result = (result + dp[state]) % MOD;
        }

        // Multiply by powers of 2 for the number of 1s
        int powerOfTwo = 1;
        for (int i = 0; i < freq[1]; ++i) {
            powerOfTwo = (powerOfTwo * 2) % MOD;
        }
        result = (long long)result * powerOfTwo % MOD;

        return result;
    }
};