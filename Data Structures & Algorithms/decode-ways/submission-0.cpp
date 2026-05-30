class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        int dp1 = 1; // dp[n] = 1 (empty string)
        int dp2 = 0; // dp[n+1] = 0 (out of bounds)

        for (int i = n - 1; i >= 0; i--) {

            int cur = 0;

            // single digit check
            if (s[i] != '0') {
                cur = dp1;
            }

            // two digit check
            if (i + 1 < n) {
                int twoDigit = (s[i] - '0') * 10 + (s[i + 1] - '0');
                if (twoDigit >= 10 && twoDigit <= 26) {
                    cur += dp2;
                }
            }

            dp2 = dp1;
            dp1 = cur;
        }

        return dp1;
    }
};
