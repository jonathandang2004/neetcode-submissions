class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        // Put all treasure cells into the queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        vector<pair<int,int>> dirs = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : dirs) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx < 0 || ny < 0 ||
                    nx >= m || ny >= n) {
                    continue;
                }

                // Skip walls and already-visited rooms
                if (grid[nx][ny] != INT_MAX) {
                    continue;
                }

                grid[nx][ny] = grid[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
};