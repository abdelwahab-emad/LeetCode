class Solution {
public:
    vector<int> dp;
    int n;
    int go(int idx, vector<int>&v, int d) {
        int &ret = dp[idx];
        if (~ret) return ret;
        ret = 1;
        for(int i = idx + 1; i <= min(n - 1, idx + d);i++) {
            if (v[i] >= v[idx]) break;
            ret = max(ret, 1 + go(i, v, d));
        }
        for(int i = idx - 1;i >= max(0, idx - d);i--) {
            if (v[i] >= v[idx]) break;
            ret = max(ret, 1 + go(i, v, d));
        }
        return ret;
    }
    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        dp.assign(n, -1);
        int ans = 1;
        for(int i = 0;i < n;i++) {
            ans = max(ans, go(i, arr, d));
        }
        return ans;
    }
};