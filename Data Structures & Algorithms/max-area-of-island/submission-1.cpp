class Solution {
private:
    int dfs(int x, int y, vector<vector<int>>& grid) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[x].size() || grid[x][y] == 0) {
            return 0;
        }
        grid[x][y] = 0;
        return 1 + dfs(x - 1, y, grid) + dfs(x, y - 1, grid) + dfs(x + 1, y, grid) + dfs(x, y + 1, grid);

    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(i, j, grid));
                }
            }
        }

        return maxArea;

    }
};
