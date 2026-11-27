
class Solution {
public:
    int n;
    vector<int> bonus;
    vector<vector<int>> dp;

    int solve(int i, int b, vector<vector<int>>& items) {
        if (i == n) return 0;
        int &ret = dp[i][b];
        if (ret != -1) return ret;
        ret = solve(i + 1, b, items);
        int price = items[i][1];
        if (b >= price) {
            ret = max(ret, 1 + bonus[i] + solve(i + 1, b - price, items));
            ret = max(ret, 1 + solve(i, b - price, items));
        }
        return ret;
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n = items.size();
        bonus.assign(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    bonus[i]++;
                }
            }
        }
        dp.assign(n, vector<int>(budget + 1, -1));
        return solve(0, budget, items);
    }
};
