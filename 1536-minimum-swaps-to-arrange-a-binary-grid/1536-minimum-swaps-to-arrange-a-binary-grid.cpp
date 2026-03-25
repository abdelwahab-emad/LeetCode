class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> row_zeros;
        for (int i = 0; i < n; ++i) {
            int zeros = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) zeros++;
                else break;
            }
            row_zeros.push_back(zeros);
        }
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int target = n - 1 - i;
            int idx = -1;
            for (int j = i; j < n; ++j) {
                if (row_zeros[j] >= target) {
                    idx = j;
                    break;
                }
            }

            if (idx == -1) return -1;

            ans += (idx - i);
            
            int val = row_zeros[idx];
            row_zeros.erase(row_zeros.begin() + idx);
            row_zeros.insert(row_zeros.begin() + i, val);
        }

        return ans;
    }
};