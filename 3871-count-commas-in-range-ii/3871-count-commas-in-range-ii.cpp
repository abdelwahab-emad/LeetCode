class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long l = 1, r = 9;
        int d = 1;
        while (l <= n) {
            long long mx = min(n, r);
            long long cnt = mx - l + 1;
            int commas = (d - 1) / 3;
            ans += cnt * commas;
            l = r + 1;
            r = r * 10 + 9;
            d++;
        }
        return ans;
    }
};