class Solution {
public:
    int m, n;
    vector<vector<int>> coins;
    int dp[501][501][3];

    int solve(int i, int j, int cnt) {
        if (i >= m || j >= n) return -1000000000;
        if (i == m - 1 && j == n - 1) {
            if (coins[i][j] >= 0) return coins[i][j];
            if (cnt < 2) return 0;
            return coins[i][j];
        }
        int &ret = dp[i][j][cnt];
        if (ret != -1000000000) return ret;
        int val = coins[i][j];
        if (val >= 0) {
            ret = val + max(solve(i + 1, j, cnt), solve(i, j + 1, cnt));
        } else {
            int take = val + max(solve(i + 1, j, cnt), solve(i, j + 1, cnt));
            int skip = -1000000000;
            if (cnt < 2) {
                skip = max(solve(i + 1, j, cnt + 1), solve(i, j + 1, cnt + 1));
            }
            ret = max(take, skip);
        }
        return ret;
    }

    int maximumAmount(vector<vector<int>>& grid) {
        coins = grid;
        m = coins.size();
        n = coins[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < 3; k++)
                    dp[i][j][k] = -1000000000;
        return solve(0, 0, 0);
    }
};