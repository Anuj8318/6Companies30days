// 2223. Sum of Scores of Built Strings
// https://leetcode.com/problems/sum-of-scores-of-built-strings/

class Solution {
public:
    static constexpr int64_t MOD = 1000000007;
    long long sumScores(string_view s) {
        const int64_t N = s.length();
        int64_t h1 = 0, h2 = 0, prod = 1, sum = N;
        for (size_t i = 0, j = N - 1; j > 0; ++i, --j) {
            h1 = (h1 * 26 + s[i] - 'a') % MOD;
            h2 = (h2 + prod * (s[j] - 'a')) % MOD;
            prod *= 26, prod %= MOD;
            if (h1 == h2) {
                sum += (i + 1);
            } else {
                size_t p = 0, k = j;
                while(s[p] == s[k]) {
                    ++k, ++p;
                }
                sum += p;
            }
        }
        return sum;
    }
};