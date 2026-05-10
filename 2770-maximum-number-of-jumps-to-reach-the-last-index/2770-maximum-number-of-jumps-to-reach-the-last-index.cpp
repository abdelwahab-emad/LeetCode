class Solution {
public:
    int n;
    vector<vector<int >> dp;
    int go(int idx, int pre, int target, vector<int>& nums) {
        if (idx == n - 1) {
            if (abs(nums[idx] - nums[pre]) <= target)
                return 1;
            return -1e9;
        }
        int &ret = dp[idx][pre];
        if (ret != -1)
            return ret;
        ret = -1e9;
        if (abs(nums[idx] - nums[pre]) <= target)
            ret = max(ret, 1 + go(idx + 1, idx, target, nums));
        ret = max(ret, go(idx + 1, pre, target, nums));
        return ret;
    }
    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
        int ans = go(1, 0, target, nums);
        return ans < 0 ? -1 : ans;
    }
};