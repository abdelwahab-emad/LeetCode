class Solution {
  int countCommas(int n) {
    int l  = 1, r = 9;
    int d = 1;
    int ans = 0;
    while (l <= n) {
        int mx = min(n, r);
        int cnt = mx - l + 1;
        int commas = (d - 1) ~/ 3;
        ans += cnt * commas;
        l = r + 1;
        r = r * 10 + 9;
        d++;
    }
    return ans;
  }
}