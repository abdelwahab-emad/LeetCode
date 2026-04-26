class Solution {
public:
    int m, n;
    vector<vector<bool>> vis;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool dfs(int x, int y, int px, int py, vector<vector<char>>& grid) {
        vis[x][y] = true;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;

            if (grid[nx][ny] != grid[x][y])
                continue;

            if (!vis[nx][ny]) {
                if (dfs(nx, ny, x, y, grid))
                    return true;
            } else if (!(nx == px && ny == py)) {
                return true;
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vis.assign(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) {
                    if (dfs(i, j, -1, -1, grid))
                        return true;
                }
            }
        }

        return false;
    }
};