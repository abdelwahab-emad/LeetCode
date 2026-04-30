class Solution {
public:
    int m, n;
    vector<vector<int>> grid;
    vector<vector<vector<int>>> memo;
    
    int dfs(int i, int j, int k) {
        if (i >= m || j >= n) return -1e9;
        
        int cost = (grid[i][j] == 0 ? 0 : 1);
        if (k < cost) return -1e9;
        
        if (i == m - 1 && j == n - 1) return grid[i][j];
        
        int &res = memo[i][j][k];
        if (res != -1) return res;
        
        int nk = k - cost;
        
        int right = dfs(i, j + 1, nk);
        int down = dfs(i + 1, j, nk);
        
        int best = max(right, down);
        if (best < 0) return res = -1e9;
        
        return res = grid[i][j] + best;
    }
    
    int maxPathScore(vector<vector<int>>& g, int k) {
        grid = g;
        m = grid.size();
        n = grid[0].size();
        
        memo.assign(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        
        int ans = dfs(0, 0, k);
        return ans < 0 ? -1 : ans;
    }
};