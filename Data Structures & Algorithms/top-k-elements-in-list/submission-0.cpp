class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> frequency;
        vector<int> out;
        vector<pair<int, int>> ordered;
        for (auto& num : nums) {
            if (!frequency.contains(num)) frequency.insert({num, 1});
            else frequency[num]++;
        }
        for (auto& [num, freq] : frequency) {
            ordered.push_back({freq, num});
        }
        sort(ordered.begin(), ordered.end(), greater<>());
        for (int i = 0; i < k; i++) {
            out.push_back(ordered[i].second);
        }
        return out;
    }
};
