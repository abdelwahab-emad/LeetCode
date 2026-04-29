class Solution {
    long long dp[2][101][101];
    long long pref[101][101];
    int n;

    long long solve(int prevTaken, int prevLen, int col) {
        if (col == n + 1)
            return 0;
 
        long long &res = dp[prevTaken][prevLen][col];
        if (~res) return res;
         
        res = 0;

        for (int len = 0; len <= n; len++) {
            long long prevans = 0;
            long long currans = 0;

            if (prevTaken == 0 && col > 1 && len > prevLen) {
                prevans = pref[len][col - 1] - pref[prevLen][col - 1];
            }

            if (prevLen > len) {
                currans = pref[prevLen][col] - pref[len][col];
            }

            long long ans1 = currans + prevans + solve(1, len, col + 1);
            long long ans2 = prevans + solve(0, len, col + 1);

            res = max({res, ans1, ans2});
        }

        return res;
    }

public:
    long long maximumScore(vector<vector<int>>& grid) {
        n = grid.size();
        memset(dp, -1, sizeof(dp));
        memset(pref, 0, sizeof(pref));

        for (int j = 0; j < n; j++) {
            for (int i = 1; i <= n; i++) {
                pref[i][j + 1] = pref[i - 1][j + 1] + (long long)grid[i - 1][j];
            }
        }

        return solve(0, 0, 1);
    }
};