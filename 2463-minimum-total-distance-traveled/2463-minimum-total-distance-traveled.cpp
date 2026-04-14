class Solution {
public:
    long long dp[101][101];

    long long solve(int rob_idx, int fact_idx, vector<int>& robot,
                    vector<vector<int>>& factory) {
        if (rob_idx == robot.size())
            return 0;
        if (fact_idx == factory.size())
            return 1e15;
        long long& ret = dp[rob_idx][fact_idx];
        if (~ret)
            return ret;

        ret = solve(rob_idx, fact_idx + 1, robot, factory);
        long long cur_dis = 0;

        for (int k = 1; k <= factory[fact_idx][1]; k++) {
            if (rob_idx + k - 1 >= robot.size())
                break;

            cur_dis +=
                abs((long long)robot[rob_idx + k - 1] - factory[fact_idx][0]);
            ret = min(ret, cur_dis + solve(rob_idx + k, fact_idx + 1, robot,
                                           factory));
        }

        return ret;
    }

    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, robot, factory);
    }
};