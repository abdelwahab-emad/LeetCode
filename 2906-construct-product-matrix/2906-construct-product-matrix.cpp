class Solution {
public:
    const int MOD = 12345;
    int mul(int a, int b) {
         return ((a % MOD) * (b % MOD)) % MOD;
    }
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> arr;
        for (auto &row : grid)
            for (auto x : row)
                arr.push_back(x);

        int sz = arr.size();
        vector<int> prefix(sz, 1), suffix(sz, 1);
        for (int i = 1; i < sz; i++)
            prefix[i] = mul(prefix[i - 1], arr[i - 1]);

        for (int i = sz - 2; i >= 0; i--)
            suffix[i] = mul(suffix[i + 1], arr[i + 1]);

        vector<vector<int>> res(n, vector<int>(m));
        int idx = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = (prefix[idx] * suffix[idx]) % MOD;
                idx++;
            }
        }
        return res;
    }
};