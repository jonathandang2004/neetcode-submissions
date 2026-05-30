class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    //     return max(traverse(nums, 1, nums[0], 1), traverse(nums, 0, -1001, 1));
    // }

    // int traverse(vector<int>& nums, int curLen, int mx, int curPos) {
    //     if (curPos == nums.size() - 1) {
    //         return curLen + (mx < nums[curPos] ? 1 : 0);
    //     }

    //     // return curLen + 
    //     if (mx < nums[curPos]) {
    //         return max(traverse(nums, curLen + 1, nums[curPos], curPos + 1), traverse(nums, curLen, mx, curPos + 1));
    //     } else {
    //         return traverse(nums, curLen, mx, curPos + 1);
    //     }
    //     // max(traverse(nums, curLen + 1, mx, curPos + 1); 
        int n = nums.size();
        vector<int> dp(n, 1);

        int best = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            best = max(best, dp[i]);
        }

        return best;
    }
};
