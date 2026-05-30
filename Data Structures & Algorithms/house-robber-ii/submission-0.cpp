class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

    if (n == 1) return nums[0];

    return max(
        solve(nums, 0, n - 2),
        solve(nums, 1, n - 1)
    );
    }
    // OHHHHH, just split it into 0 -> n - 1, and 1 -> n
    int solve(vector<int>& nums, int start, int end) {
    vector<vector<int>> dp(end - start + 1, vector<int>(2));

    dp[0][0] = 0;
    dp[0][1] = nums[start];

    for (int i = 1; i <= end - start; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[i - 1][0] + nums[start + i];
    }

    return max(dp.back()[0], dp.back()[1]);
}
};
