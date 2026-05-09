class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int layers = min(m, n) / 2;
        for (int layer = 0; layer < layers; layer++) {
            vector<int> arr;
            int top = layer, left = layer;
            int bottom = m - layer - 1;
            int right = n - layer - 1;
            for (int i = top; i <= bottom; i++)
                arr.push_back(grid[i][left]);
            for (int j = left + 1; j <= right; j++)
                arr.push_back(grid[bottom][j]);
            for (int i = bottom - 1; i >= top; i--)
                arr.push_back(grid[i][right]);
            for (int j = right - 1; j > left; j--)
                arr.push_back(grid[top][j]);

            int len = arr.size();
            int rot = k % len;

            vector<int> rotated(len);

            for (int i = 0; i < len; i++)
                rotated[i] = arr[(i - rot + len) % len];

            int idx = 0;

            for (int i = top; i <= bottom; i++)
                grid[i][left] = rotated[idx++];

            for (int j = left + 1; j <= right; j++)
                grid[bottom][j] = rotated[idx++];

            for (int i = bottom - 1; i >= top; i--)
                grid[i][right] = rotated[idx++];

            for (int j = right - 1; j > left; j--)
                grid[top][j] = rotated[idx++];
        }

        return grid;
    }
};