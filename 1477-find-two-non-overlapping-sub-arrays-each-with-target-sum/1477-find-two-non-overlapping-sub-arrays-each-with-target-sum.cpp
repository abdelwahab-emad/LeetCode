class Solution {
public:
    vector<int> nxt;
    int n;
    vector<vector<int>> dp;
    int go(int idx, int take) {
        if (idx == n) {
            if (take == 2) return 0;
            return 1e9;
        }
        int &ret = dp[idx][take];
        if (~ret) return ret;
        ret = go(idx + 1, take);
        if (take < 2 and nxt[idx] != -1) {
            ret = min(ret, nxt[idx] - idx + 1 + go(nxt[idx] + 1, take + 1));
        }
        return ret;
    }
    int minSumOfLengths(vector<int>& arr, int target) {
        n = arr.size();
        nxt.assign(n, -1);
        dp = vector<vector<int>>(n + 1, vector<int>(3, -1));
        for (int i = 1;i < n;i++) arr[i] += arr[i - 1];
        for (int i = 0;i < n;i++) {
            int l = i, r = n - 1, idx = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                int sum = arr[mid] - (i > 0 ? arr[i - 1] : 0);
                if (sum == target) {
                    idx = mid;
                    break;
                }
                if (sum < target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if (idx != -1) {
                nxt[i] = idx;
            }
        }
        for (int i = 0;i < n;i++) cout << nxt[i] << " ";
        cout << endl;
        int ans = go(0, 0);
        return (ans >= 1e9 ? -1 : ans);
    }
};