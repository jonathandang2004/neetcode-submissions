class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curmin = INT_MAX;
        int prof = INT_MIN;
        for (int i = 0; i < prices.size(); ++i) {
            curmin = min(curmin, prices[i]);
            prof = max(prof, prices[i] - curmin);
        }
        return prof;
    }
};
