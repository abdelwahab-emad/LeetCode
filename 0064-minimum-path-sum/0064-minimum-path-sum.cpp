class Solution {
public:
    long long mod = 2 * 1e9;

    long long add(long long a, long long b) {
        return ((a % mod) + (b % mod)) % mod;
    }

    vector<vector<long long>> dp;
    vector<vector<int>> grid;

    long long solve(int i, int j, int m, int n) {
        if (i == m - 1 && j == n - 1) return grid[i][j];
        long long &ret = dp[i][j];
        if (~ret) return ret;
        ret = 1e18;
        if (i + 1 < m)
            ret = min(ret, solve(i + 1, j, m, n) + grid[i][j]);
        if (j + 1 < n)
            ret = min(ret, solve(i, j + 1, m, n) + grid[i][j]);
        return ret;
    }

    int minPathSum(vector<vector<int>>& inputGrid) {
        grid = inputGrid;
        int m = grid.size();
        int n = grid[0].size();
        dp.assign(m, vector<long long>(n, -1));
        return solve(0, 0, m, n);
    }
};
