class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorsum = 0;
        for (int i = 0; i <= nums.size(); ++i) {
            if (i != nums.size()) xorsum ^= nums[i];
            xorsum ^= i;
        }
        return xorsum;
    }
};
