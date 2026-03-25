class DP{
    public:
    vector<vector<vector<int>>>dp;
    vector<int>v;
    int n;
    DP(int siz, vector<int>& prices){
        v = prices;
        n = siz;
        dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
    }
    int solve(int idx, bool buy, int rem){
        if(idx == n or rem <= 0){
            return 0;
        }
        int &ret = dp[idx][buy][rem];
        if(~ret)return ret;
        ret = solve(idx + 1, buy, rem);
        if(buy){
            ret = max(ret, solve(idx + 1, 0, rem - 1) + v[idx]); // sell 
            ret = max(ret, solve(idx + 1, 1, rem)); // sell then buy on same day
        }
        else{
            ret = max(ret, solve(idx + 1, 1, rem) - v[idx]); // buy
        }
        return ret;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        DP dp(prices.size(), prices);
        return dp.solve(0, 0, 2);
    }
};