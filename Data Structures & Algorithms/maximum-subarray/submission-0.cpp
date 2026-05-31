class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // int start = 0;
        int maxSum = nums[0];
        int curSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (curSum < 0) curSum = 0;
            curSum += nums[i];
            maxSum = max(maxSum, curSum);
            // curSum = nums[i];
        }
        return maxSum;
    }
};
