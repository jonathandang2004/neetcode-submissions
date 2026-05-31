class Solution {
public:
    int search(vector<int>& nums, int target) {
        int upper = nums.size() - 1;
        int lower = 0;
        int mid = 0;
        while (lower <= upper) {
            mid = lower + (upper - lower) / 2;
            if (target > nums[mid]) {
                lower = mid + 1;
            } else if (target < nums[mid]) {
                upper = mid - 1;
            } else {
                return mid;
            }
            // cout << mid << endl;
        }
        return -1;
    }
};
