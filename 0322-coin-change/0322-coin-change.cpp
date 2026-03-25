class DP{
    public:
    vector<int>dp;
    vector<int>v;
    int n, target;
    DP(vector<int>& prices, int amount){
        v = prices;
        n = v.size();
        target = amount;
        dp = vector<int>(amount + 1, -1);
    }
    int solve(int rem){
        if(rem == 0)return 0;
        
        int &ret = dp[rem];
        if(~ret)return ret;

        ret = 100000;
        for(int i = 0;i < n;i++){
            if(rem >= v[i]){
                ret = min(ret, solve(rem - v[i]) + 1);
            }
        }
        return ret;
    }
};
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        DP dp(coins, amount);
        int ans = dp.solve(amount);
        if(ans == 100000)ans = -1;
        return ans;
    }
};