// Number following a pattern
// https://www.geeksforgeeks.org/problems/number-following-a-pattern3126/1


class Solution {
public:
    string printMinNumberForPattern(string& s)
    {

        int n = s.size();

        int cnt = 1;
        string ans(n + 1, ' ');

        for (int i = 0; i <= n; i++) {
            if (i == n || s[i] == 'I') {
                for (int j = i - 1; j >= -1; j--) {
                    ans[j + 1] = char('0' + cnt);
                    cnt++;
                    if (j >= 0 && s[j] == 'I') {
                        break;
                    }
                }
            }
        }

        return ans;
    }
};