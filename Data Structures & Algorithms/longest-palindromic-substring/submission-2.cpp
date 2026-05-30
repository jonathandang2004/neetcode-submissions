class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.size();
        // int maxVal = 0;
        int start = 0, curLen = 0;;
        vector<vector<bool>> dp(sz, vector<bool>(sz, false));
        for (int i = 0; i < sz; ++i) {
            dp[i][i] = true;
            if (curLen == 0) curLen = 1;
            if (i != 0 && s[i] == s[i - 1]) {
                // cout << "kys" << endl;
                dp[i - 1][i] = true;
                start = i - 1;
                curLen = 2;
            }
        }
        for (int k = 2; k < sz; ++k) {
            for (int i = 0; i < sz - k; ++i) {
                dp[i][i + k] = (s[i] == s[i + k] && dp[i + 1][i + k - 1]);
                // cout << dp[i + 1][i + k - 1] << " " << i << " " << k << endl;
                // cout << s[i] << " " << s[i + k] << endl;
                // cout << dp[i][i + k] << endl;
                if (dp[i][i + k] && k + 1 > curLen) {
                    start = i;
                    curLen = k + 1;
                }
            }
        }
        cout << start << " " << curLen << endl;
        return s.substr(start, curLen);
    }
};
