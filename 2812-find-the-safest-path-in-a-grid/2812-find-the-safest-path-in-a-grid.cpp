class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == INT_MAX) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        auto can = [&](int val) {
            if (dist[0][0] < val || dist[n - 1][n - 1] < val) return false;
            queue<pair<int,int>> qq;
            vector<vector<int>> vis(n, vector<int>(n, 0));
            qq.push({0, 0});
            vis[0][0] = 1;
            while (!qq.empty()) {
                auto [x, y] = qq.front();
                qq.pop();
                if (x == n - 1 && y == n - 1) return true;
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                        !vis[nx][ny] && dist[nx][ny] >= val) {
                        vis[nx][ny] = 1;
                        qq.push({nx, ny});
                    }
                }
            }
            return false;
        };

        int lo = 0, hi = 2 * n;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (can(mid)) lo = mid;
            else hi = mid - 1;
        }

        return lo;
    }
};