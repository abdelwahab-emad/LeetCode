class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size(), m = boxGrid[0].size();
        for (int i = 0; i < n; i++) {
            int empty = m - 1;
            for (int j = m - 1; j >= 0; j--) {
                if (boxGrid[i][j] == '*') {
                    empty = j - 1;
                } else if (boxGrid[i][j] == '#') {
                    swap(boxGrid[i][j], boxGrid[i][empty]);
                    empty--;
                }
            }
        }
        vector<vector<char>> res(m, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[j][n - 1 - i] = boxGrid[i][j];
            }
        }
        return res;
    }
};