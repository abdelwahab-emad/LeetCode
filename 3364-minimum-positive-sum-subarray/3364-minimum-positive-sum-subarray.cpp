class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = 1e9;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n && j - i + 1 <= r; j++) {
                sum += nums[j];
                int len = j - i + 1;
                if (len >= l && sum > 0) {
                    ans = min(ans, sum);
                }
            }
        }
        return ans == 1e9 ? -1 : ans;
    }
};