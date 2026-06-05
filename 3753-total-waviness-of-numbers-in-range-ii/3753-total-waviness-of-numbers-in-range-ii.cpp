class Solution {
public:
    struct Node {
        long long ways;
        long long wav;
    };
    string s;
    Node dp[20][11][11][3][2][2];
    bool vis[20][11][11][3][2][2];
    Node go(int idx, int ls1, int ls2, int len, int tight, int start) {
        if (idx == s.size()) {
            return {1, 0};
        }
        if (vis[idx][ls1][ls2][len][tight][start])
            return dp[idx][ls1][ls2][len][tight][start];

        vis[idx][ls1][ls2][len][tight][start] = true;

        Node res = {0, 0};
        int end = tight ? s[idx] - '0' : 9;
        for (int d = 0; d <= end; d++) {
            int ntight = tight and (d == end);
            if (!start and d == 0) {
                Node nxt = go(idx + 1, ls1, ls2, len, ntight, 0);
                res.ways += nxt.ways;
                res.wav += nxt.wav;
            } else {
                long long add = 0;
                int nlen = min(2, len + 1);
               if (len >= 2) {
                    if ((ls2 < ls1 and ls1 > d) or
                        (ls2 > ls1 and ls1 < d))
                        add = 1;
                }
                int nls1, nls2;
                if (len == 0) {
                    nls2 = 10;
                    nls1 = d;
                } else  {
                    nls2 = ls1;
                    nls1 = d;
                }
                Node nxt = go(idx + 1, nls1, nls2, nlen, ntight, 1); 
                res.ways += nxt.ways;
                res.wav += nxt.wav + add * nxt.ways;
            }
        }
        return dp[idx][ls1][ls2][len][tight][start] = res;
    }
    long long solve (long long x) {
        if (x <= 0) return 0;
        s = to_string(x);
        memset(vis, 0, sizeof(vis));
        return go(0, 10, 10, 0, 1, 0).wav;
    }
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);   
    }
};