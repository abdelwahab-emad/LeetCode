class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int F = 0;
        for(int i = 0;i < n;i++) {
            sum += nums[i];
            F += i * nums[i]; 
        }
        int ans = F;
        for(int k = 1;k < n;k++) {
            F = F + sum - n * nums[n - k];
            ans = max(ans, F);
        }
        return ans;
    }
};