
class Solution {
public:
    int solve(int i, int n, vector<int>& costs, vector<int>& dp) {
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];
        int ans = 1e9;
        for (int j = 1; j <= 3; j++) {
            if (i + j <= n) {
                ans = min(ans, costs[i + j - 1] + j * j + solve(i + j, n, costs, dp));
            }
        }
        return dp[i] = ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, -1);
        return solve(0, n, costs, dp);
    }
};
