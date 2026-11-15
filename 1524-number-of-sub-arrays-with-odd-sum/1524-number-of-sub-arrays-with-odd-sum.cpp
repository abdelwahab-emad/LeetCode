class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[100005][2][2];
    vector<int> arr;
    int n;
    int solve(int idx, int odd, int started) {
        if (idx == n) return started && odd;
        int& ret = dp[idx][odd][started];
        if (ret != -1) return ret;
        if (!started) {
            ret = (solve(idx + 1, 0, 0) + solve(idx + 1, arr[idx] % 2, 1)) % MOD;
        } else {
            ret = (odd + solve(idx + 1, (odd + arr[idx]) % 2, 1)) % MOD;
        }
        return ret;
    }

    int numOfSubarrays(vector<int>& nums) {
        arr = nums;
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0);
    }
};