class Solution {
public:
    vector<vector<vector<int>>> dp;
    int n, m;
    string S, T;
    int go (int i, int j, int take) {
        if (j == m) return 1;
        if (i == n) {
            return 0;
        }
        int &ret = dp[i][j][take];
        if (~ret) return ret;
        ret = 0;
        if (S[i] == T[j]) ret += go(i + 1, j + 1, 1);
        ret += go(i + 1, j, take);
        return ret;
    }
    int numDistinct(string s, string t) {
        n = s.size();
        m = t.size();
        S = s, T = t;
        dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(m + 1, vector<int>(3, -1)));
        return go(0, 0, 0);
    }
};