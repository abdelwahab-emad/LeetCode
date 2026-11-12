class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n, 1), dp2(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                dp1[i] = dp1[i - 1] + 1;
            }
            if (nums[i] < nums[i - 1]) {
                dp2[i] = dp2[i - 1] + 1;
            }
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            ans = max({ans, dp1[i], dp2[i]});
        }
        return ans;
    }
};