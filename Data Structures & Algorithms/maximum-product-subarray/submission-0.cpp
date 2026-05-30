class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int gmax = nums[0];
        int curmax = nums[0];
        int curmin = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int curval = nums[i];
            if (curval < 0) {
                swap(curmax, curmin);
            }
            curmax = max(curval, curmax * curval);
            curmin = min(curval, curmin * curval);

            gmax = max(gmax, curmax);
        }
        return gmax;
    }
};
