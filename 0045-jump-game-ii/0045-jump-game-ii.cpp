class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        function<int(int)> solve = [&](int idx){
            if(idx >= n - 1){
                if(idx == n - 1)return 0;
                return 10000000;
            }
            int &ret = dp[idx];
            if(~ret)return ret;
            ret = 1e9;
            for(int i = 1;i <= nums[idx];i++){
                ret = min(ret, 1 + solve(idx + i));
            }
            return ret;
        }; 
        return solve(0);
    }
};