class Solution {
    int dp[301][27][27];

    int getDist(int from, int to) {
        if (from == 26) return 0;
        int r1 = from / 6, c1 = from % 6;
        int r2 = to / 6, c2 = to % 6;
        return abs(r1 - r2) + abs(c1 - c2);
    }

    int solve(int idx, int f1, int f2, string& word) {
        if (idx == word.length()) return 0;
        
        int &ret = dp[idx][f1][f2];
        if (~ret) return ret;

        int target = word[idx] - 'A';

        int F1 = getDist(f1, target) + solve(idx + 1, target, f2, word);
        int F2 = getDist(f2, target) + solve(idx + 1, f1, target, word);

        return ret = min(F1, F2);
    }

public:
    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 26, 26, word);
    }
};