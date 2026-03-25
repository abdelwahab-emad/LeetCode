class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<long long> rows(n);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                rows[i] += grid[i][j];
            }
        }
        for(int i = 1;i < n;i++)rows[i] += rows[i - 1];
        for(int i = 0;i < n - 1;i++){
            long long up = rows[i], down = rows[n - 1] - rows[i];
            if(up == down)return true;
        }
        
        vector<long long> cols(m);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                cols[j] += grid[i][j];
            }
        }
        for(int i = 1;i < m;i++)cols[i] += cols[i - 1];
        for(int i = 0;i < m - 1;i++){
            long long left = cols[i], right = cols[m - 1] - cols[i];
            if(left == right)return true;
        }
        
        return false;
    }
};