class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int left[n], right[n];
        for (int i = 0; i < n; ++i) {
            left[i] = (i == 0) ? 1 : left[i - 1] * nums[i - 1];
            right[n - i - 1] = (i == 0) ? 1 : right[n - i] * nums[n - i];

            // left[i] = (i == 0) ? 1 : (i == 1) ? nums[0] : left[i - 1] * nums[i - 1];
            // right[i] = (i == n - 1) ? 1 : (i == n - 2) ? nums[n - 1] : right[i + 1] * nums[i + 1];
        }
        vector<int> vec;
        for (int i = 0; i < n; ++i) {
            
            vec.push_back(left[i] * right[i]);
            
        }
        return vec;
    }
};
