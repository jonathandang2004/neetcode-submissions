class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 0; // 0 means doesn't have coin
        dp[0][1] = -prices[0]; // 1 means has coin
        // dp[0][2] = 0 // 2 means sells coin on current day
        // dp[0][2] = 0; // 2 means just sold, cannot but for i + 1
        // dp[i] represents the max profit on the current day
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][1] + prices[i], dp[i - 1][0]);
            if (i == 1) {
                dp[i][1] = max(dp[i- 1][1], -prices[i]);
            } else {
                dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
            }
        }
        // I could also use the fact that if i buy, i can only consider i - 2


        // 0 2 3
        // -1 -1 
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};
