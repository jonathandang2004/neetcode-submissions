class Solution {
private:
    //bfs(int)
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int curTurns = 0;

        vector<pair<int, int>>dirs = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };
        queue<pair<int, pair<int, int>>> que;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    que.push({0, {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        while (!que.empty()) {
            auto [turn, coord] = que.front();
            auto [x, y] = coord;
            que.pop();

            for (auto& [dx, dy] : dirs) {
                if (x + dx < 0 || x + dx >= m || y + dy < 0 || y + dy >= n) {
                    continue;
                }
                if (!visited[x + dx][y + dy] && grid[x + dx][y + dy] == 1) {
                    que.push({turn + 1, {x + dx, y + dy}});
                    visited[x + dx][y + dy] = true;
                    curTurns = max(curTurns, turn + 1);
                    grid[x + dx][y + dy] = 2;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return curTurns;
    }
};
