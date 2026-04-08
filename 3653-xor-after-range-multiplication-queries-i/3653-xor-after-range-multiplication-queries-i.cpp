class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;
        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            int idx = l;
            v %= mod;
            while (idx <= r) {
                long long val = nums[idx];
                val %= mod;
                val *= v;
                val %= mod;
                nums[idx] = val;
                idx += k;
            }
        }
        int ans = 0;
        for (auto val : nums)
            ans ^= val;
        return ans;
    }
};