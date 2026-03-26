class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        long long total_sum = 0;
        unordered_map<int, int> frq_total;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                total_sum += grid[i][j];
                frq_total[grid[i][j]]++;
            }
        }

        long long current_up = 0;
        unordered_map<int, int> frq_up;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m; j++) {
                current_up += grid[i][j];
                frq_up[grid[i][j]]++;
            }
            long long current_down = total_sum - current_up;
            if (current_up == current_down) return true;

            if (current_up > current_down) {
                long long diff = current_up - current_down;
                if (diff <= 100000 && frq_up[diff] > 0) {
                    if (i + 1 > 1 && m > 1) return true;
                    if (grid[0][0] == diff || grid[i][m - 1] == diff || grid[0][m - 1] == diff || grid[i][0] == diff) return true;
                }
            } else {
                long long diff = current_down - current_up;
                if (diff <= 100000 && (frq_total[diff] - frq_up[diff]) > 0) {
                    if (n - 1 - i > 1 && m > 1) return true;
                    if (grid[i + 1][0] == diff || grid[n - 1][m - 1] == diff || grid[i + 1][m - 1] == diff || grid[n - 1][0] == diff) return true;
                }
            }
        }

        long long current_left = 0;
        unordered_map<int, int> frq_left;
        for (int j = 0; j < m - 1; j++) {
            for (int i = 0; i < n; i++) {
                current_left += grid[i][j];
                frq_left[grid[i][j]]++;
            }
            long long current_right = total_sum - current_left;
            if (current_left == current_right) return true;

            if (current_left > current_right) {
                long long diff = current_left - current_right;
                if (diff <= 100000 && frq_left[diff] > 0) {
                    if (j + 1 > 1 && n > 1) return true;
                    if (grid[0][0] == diff || grid[n - 1][j] == diff || grid[0][j] == diff || grid[n - 1][0] == diff) return true;
                }
            } else {
                long long diff = current_right - current_left;
                if (diff <= 100000 && (frq_total[diff] - frq_left[diff]) > 0) {
                    if (m - 1 - j > 1 && n > 1) return true;
                    if (grid[0][j + 1] == diff || grid[n - 1][m - 1] == diff || grid[0][m - 1] == diff || grid[n - 1][j + 1] == diff) return true;
                }
            }
        }
        return false;
    }
};