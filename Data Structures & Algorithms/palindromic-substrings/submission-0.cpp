class Solution {
public:
    int countSubstrings(string s) {
        int sz = s.size();
        int ans = 0;
        vector<vector<bool>> dp(sz, vector<bool>(sz, false));
        for (int i = 0; i < sz; ++i) {
            dp[i][i] = true;
            if (i != 0 && s[i] == s[i - 1]) {
                dp[i - 1][i] = true;
            }
        }
        for (int k = 2; k < sz; ++k) {
            for (int i = 0; i < sz - k; ++i) {
                dp[i][i + k] = (s[i] == s[i + k] && dp[i + 1][i + k - 1]);
            }
        }

        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                ans += dp[i][j];
            }
        }
        return ans;
    }
};
