class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> val;
        for(int j = 0;j < m;j++) {
            for(int i = n - 1;i >= 0;i--)val.push_back(matrix[i][j]);
        }
        int idx = 0;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++)matrix[i][j] = val[idx++];
        }
    }
};