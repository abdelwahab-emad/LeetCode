class Solution {
public:
    vector<int>v,dp;int n;
    int solve(int idx){
        if(idx>=n)return 0;
        int & ret = dp[idx];
        if(~ret)return ret;
        int leave = solve(idx+1);
        int take = v[idx] + solve(idx+2);
        return ret = max(leave,take);
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        v = nums;
        dp.resize(101,-1);
        return solve(0);
    }
};