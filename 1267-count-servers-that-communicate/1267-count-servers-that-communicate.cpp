class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            int idx = -1;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    if (idx == -1) {
                        idx = j;
                    } else {
                        visited[i][idx] = true;
                        visited[i][j] = true;
                    }
                }
            }
        }

        for (int j = 0; j < n; j++) {
            int idx = -1;
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 1) {
                    if (idx == -1) {
                        idx = i;
                    } else {
                        visited[idx][j] = true;
                        visited[i][j] = true;
                    }
                }
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (visited[i][j]) count++;

        return count;
    }
};