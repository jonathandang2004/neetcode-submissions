class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int sz = cost.size();
        vector<int> dp(sz + 2);
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i < sz + 2; ++i) {
            if (i == sz + 1) {
                dp[i] = dp[i - 2] + cost[i - 2];
                continue;
            }
            dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        }
        return min(dp[sz], dp[sz + 1]);
    }
};
