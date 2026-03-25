class DP{
    public:
    vector<vector<int>>dp;
    vector<int>v;
    int n;
    DP(int siz, vector<int>& prices){
        v = prices;
        n = siz;
        dp = vector<vector<int>>(n + 1, vector<int>(2, -1));
    }
    int solve(int idx, bool buy){
        if(idx == n){
            return 0;
        }
        int &ret = dp[idx][buy];
        if(~ret)return ret;
        ret = solve(idx + 1, buy);
        if(buy){
            ret = max(ret, solve(idx + 1, 0) + v[idx]); // sell 
            ret = max(ret, solve(idx + 1, 1)); // sell then buy on same day
        }
        else{
            ret = max(ret, solve(idx + 1, 1) - v[idx]); // buy
        }
        return ret;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        DP dp(prices.size(), prices);
        return dp.solve(0, 0);
    }
};