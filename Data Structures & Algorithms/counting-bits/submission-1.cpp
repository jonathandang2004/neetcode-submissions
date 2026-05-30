class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        int offset = 1;
        for (int i = 1; i <= n; ++i) {
            if (i == offset * 2) offset = i;
            dp[i] = 1 + dp[i - offset];
        }
        return dp;
    }
};
// 0 1 1 2 1 2 2 3 1 2 2 3 2 3 3 4 1 2 2 3 2