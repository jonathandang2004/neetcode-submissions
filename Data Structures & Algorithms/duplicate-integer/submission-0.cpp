class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> things;
        for (int i = 0; i < nums.size(); i++) {
            if (things.contains(nums[i])) {
                return true;
            }
            things.insert(nums[i]);
        }
        return false;
    }
};