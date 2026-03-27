class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        k %= m;
        
        for (int i = 0; i < n; i++) {
            vector<int> temp(m);
            for (int j = 0; j < m; j++) {
                if (i % 2 == 0)
                    temp[j] = mat[i][(j + k) % m];
                else
                    temp[j] = mat[i][(j - k + m) % m];
            }
            if (temp != mat[i]) return false;
        }
        return true;
    }
};