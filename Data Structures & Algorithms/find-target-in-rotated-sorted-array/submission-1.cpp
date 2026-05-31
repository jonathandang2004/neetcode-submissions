class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            } 
            
            if (nums[mid] < nums[high]) { // right half sorted
                // high = mid;   // min is in left half incl mid
                // if (target > nums[mid]) {
                //     low = mid + 1;
                // } else if (target < nums[mid]) {
                //     high = mid - 1;
                // }
                if (nums[mid] < target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            } else {
                // low = mid + 1; // min is in right half
                // if (target > nums[mid]) {
                //     low = mid;
                // } else if (target < nums[mid]) {
                //     if (target > nums[high]) {
                //         low = mid;
                //     } else {
                //         high = mid - 1;
                //     }
                //     // high = mid - 1;
                // }
                if (nums[low] <= target && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }

        return -1;
    }
};
