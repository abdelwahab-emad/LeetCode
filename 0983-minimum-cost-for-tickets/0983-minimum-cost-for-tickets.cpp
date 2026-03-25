class Solution {
public:
    int upperbound(const std::vector<int>& vec, int target) {
        int left = 0;
        int right = vec.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (vec[mid] <= target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return left;
    }
    vector<int>v,cost;
    int dp[400];int n;
    int solve(int idx){
        if(idx>=n)return 0;
        int & ret = dp[idx];
        if(~ret)return ret;
        int op1 = cost[0]+solve(idx+1);
        int l = upperbound(v,v[idx]+6);
        cout << v[idx] << " " << l << endl;
        op1 = min(op1,cost[1]+solve(l));
        l = upperbound(v,v[idx]+29);
        op1 = min(op1,cost[2]+solve(l));
        return ret = op1;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        v = days;
        cost = costs;
        n = days.size();
        memset(dp,-1,sizeof dp);
        int re = solve(0);
        return re;
    }
};