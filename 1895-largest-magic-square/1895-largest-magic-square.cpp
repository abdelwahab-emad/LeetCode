class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<long long>> row(m, vector<long long>(n + 1));
        vector<vector<long long>> col(n, vector<long long>(m + 1));
        vector<vector<long long>> d1(m + 1, vector<long long>(n + 1));
        vector<vector<long long>> d2(m + 1, vector<long long>(n + 2));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[j][i + 1] = col[j][i] + grid[i][j];
                d1[i + 1][j + 1] = d1[i][j] + grid[i][j];
                d2[i + 1][j] = d2[i][j + 1] + grid[i][j];
            }
        }
        
        int ans = 1;
        
        for (int k = 2; k <= min(m, n); k++) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    long long target = row[i][j + k] - row[i][j];
                    bool ok = true;
                    
                    for (int x = 0; x < k && ok; x++)
                        if (row[i + x][j + k] - row[i + x][j] != target)
                            ok = false;
                    
                    for (int y = 0; y < k && ok; y++)
                        if (col[j + y][i + k] - col[j + y][i] != target)
                            ok = false;
                    
                    long long a = d1[i + k][j + k] - d1[i][j];
                    long long b = d2[i + k][j] - d2[i][j + k];
                    
                    if (ok && a == target && b == target)
                        ans = max(ans, k);
                }
            }
        }
        
        return ans;
    }
};
