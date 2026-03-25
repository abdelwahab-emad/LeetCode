class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int>dp(nums.size()+2,-1);
        int n = nums.size();
        for(int i = 0;i<n;i++){
            dp[i] = nums[i];
        }
        for(int i = 1;i<n;i++){
            dp[i] = max(dp[i],dp[i-1]+nums[i]);
        }
        int mx = dp[0];
        for(int i = 0;i<n;i++){
            mx = max(mx,dp[i]);
        }
        return mx;
    }
};