class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Closest is min heap
        int distance = 0;
        vector<vector<int>> ls;
        pair<int, int> coord = {0, 0};
        int x1, y1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < points.size(); ++i) {
            x1 = points[i][0];
            y1 = points[i][1];
            pq.push({x1*x1 + y1*y1, i});
            // int hi = x1^2 + y1^2;
            // cout << x1 << " " << y1 << endl;
            // cout << hi << " " << i << endl;
        }
        for (int i = 0; i < k; ++i) {
            coord = pq.top();
            pq.pop();
            // cout << coord.first << " " << coord.second << endl;
            ls.push_back(points[coord.second]);
        }

        return ls;
    }
};
