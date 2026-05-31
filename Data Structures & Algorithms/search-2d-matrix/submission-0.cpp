class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool exists = false;
        for (int i = 0; i < matrix.size(); ++i) {
            exists = search(matrix[i], target);
            if (exists) return exists;
        }
        return exists;
    }

    bool search(vector<int>& nums, int target) {
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
                return true;
            }
            // cout << mid << endl;
        }
        return false;
    }
};
