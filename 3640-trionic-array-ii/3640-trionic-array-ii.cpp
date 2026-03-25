#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
    const long long INF = -1e18;
    vector<vector<long long>> dp;
    vector<vector<bool>> visited;
    vector<int> arr;
    int n;

    long long solve(int i, int state) {
        if (i <= 0) return INF;
        if (visited[i][state]) return dp[i][state];

        long long res = INF;
        long long curr = arr[i];
        long long prev = arr[i-1];

        if (state == 0) {
            if (curr > prev) {
                long long ans = solve(i - 1, 0);
                if (ans != INF)
                    res = max(ans + curr, prev + curr);
                else
                    res = prev + curr;
            }
        } 
        else if (state == 1) {
            if (curr < prev) {
                long long extend = solve(i - 1, 1);
                long long transition = solve(i - 1, 0);
                
                long long valExtend = (extend != INF) ? extend + curr : INF;
                long long valTrans = (transition != INF) ? transition + curr : INF;
                
                res = max(valExtend, valTrans);
            }
        } 
        else if (state == 2) {
            if (curr > prev) {
                long long extend = solve(i - 1, 2);
                long long transition = solve(i - 1, 1);
                
                long long valExtend = (extend != INF) ? extend + curr : INF;
                long long valTrans = (transition != INF) ? transition + curr : INF;
                
                res = max(valExtend, valTrans);
            }
        }

        visited[i][state] = true;
        dp[i][state] = res;
        return res;
    }

public:
    long long maxSumTrionic(vector<int>& nums) {
        n = nums.size();
        if (n < 4) return 0;

        arr = nums;
        dp.assign(n, vector<long long>(3, 0));
        visited.assign(n, vector<bool>(3, false));

        long long ans = INF;

        for (int i = 0; i < n; ++i) {
            long long val = solve(i, 2);
            ans = max(ans, val);
        }

        return (ans == INF) ? 0 : ans;
    }
};