class Solution {
public:
    string s;
    int dp[5][2][2][2];

    bool valid(int d) {
        return d == 0 or d == 1 or d == 8 or d == 2 or d == 5 or d == 6 or
               d == 9;
    }

    bool diff(int d) { return d == 2 or d == 5 or d == 6 or d == 9; }

    int solve(int idx, bool tight, bool leading, bool change) {
        if (idx == s.size())
            return change;

        int& ret = dp[idx][tight][leading][change];
        if (~ret)
            return ret;
        ret = 0;

        int hi = tight ? s[idx] - '0' : 9;

        for (int d = 0; d <= hi; d++) {
            bool newLeading = leading && (d == 0);

            if (!newLeading && !valid(d))
                continue;

            bool newChange = change;
            if (!newLeading && diff(d))
                newChange = true;

            ret += solve(idx + 1, tight && (d == hi), newLeading, newChange);
        }

        return ret;
    }

    int rotatedDigits(int n) {
        s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 1, 0);
    }
};