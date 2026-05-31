class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // int possible = 1000000;
        int upper = 1000000000;
        int lower = 1;
        int mid = 0;
        int ans, days = 0;
        while (lower <= upper) {
            mid = lower + (upper - lower) / 2;
            days = check(piles, mid);
            if (days > h) {
                lower = mid + 1;
            } else if (days <= h) {
                ans = mid;
                upper = mid - 1;
            }
        } 
        return ans;
    }

    int check(vector<int>& nums, int rate) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ans += (nums[i] / rate + (nums[i] % rate != 0));
        }
        return ans;
    }
};
