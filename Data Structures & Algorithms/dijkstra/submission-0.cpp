class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        vector<int> dist(n, INT_MAX);
        // vector<bool> visited(n, false);
        unordered_map<int, int> stuff;
        vector<vector<pair<int, int>>> ls(n);
        dist[src] = 0;
        // predec[src] = true;

        for (int i = 0; i < edges.size(); ++i) {
            ls[edges[i][0]].push_back(make_pair(edges[i][2], edges[i][1]));
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [weight, node] = pq.top();
            pq.pop();
            for (auto& [w2, n2] : ls[node]) {
                if (dist[n2] > w2 + dist[node]) {
                    dist[n2] = w2 + dist[node];
                    pq.push({dist[n2], n2});
                }
            }
            // if (visited[cur]) continue;
            // visited[cur] = true;
        }

        for (int i = 0; i < n; ++i) {
            stuff[i] = dist[i] == INT_MAX ? -1 : dist[i];
        }

        return stuff;
    }
};
