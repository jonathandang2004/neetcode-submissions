class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        int i1, i2 = 0;
        while (pq.size() > 1) {
            i1 = pq.top();
            pq.pop();
            i2 = pq.top();
            pq.pop();
            if (i1 != i2) pq.push(max(i1 - i2, i2 - i1)); 
        }
        return pq.size() ? pq.top() : 0;
    }
};
