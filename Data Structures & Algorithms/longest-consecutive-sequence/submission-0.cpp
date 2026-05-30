class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int seq = 0;
        set<int> numbs;
        for (int i = 0; i < nums.size(); i++) {
            numbs.insert(nums[i]);
        }
        int currSeq = 0;
        int curNum = 0;
        for (auto& val : numbs) {
            if (val != curNum + 1) {
                seq = max(seq, currSeq);
                currSeq = 1;
                curNum = val;
            } else {
                currSeq++;
                curNum++;
            }
        }
        seq = max(seq, currSeq);
        return seq;
    }
};
