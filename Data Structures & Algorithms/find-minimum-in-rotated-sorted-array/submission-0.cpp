class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;

        while (low < high) {
            mid = low + (high - low) / 2;

            if (nums[mid] <= nums[high]) {
                high = mid;   // min is in left half incl mid
            } else {
                low = mid + 1; // min is in right half
            }
        }

        return nums[low];
    }
};
