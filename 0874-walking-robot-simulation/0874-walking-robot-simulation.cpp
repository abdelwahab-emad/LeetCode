#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<long long, long long>> s;
        for (auto &o : obstacles) {
            s.insert({o[0], o[1]});
        }

        vector<pair<int,int>> d = {{0,1},{1,0},{0,-1},{-1,0}};
        int dir = 0, x = 0, y = 0;
        int ans = 0;

        for (int c : commands) {
            if (c == -2) dir = (dir + 3) % 4;
            else if (c == -1) dir = (dir + 1) % 4;
            else {
                for (int i = 0; i < c; i++) {
                    int nx = x + d[dir].first;
                    int ny = y + d[dir].second;
                    if (s.count({nx, ny})) break;
                    x = nx;
                    y = ny;
                    ans = max(ans, x * x + y * y);
                }
            }
        }
        return ans;
    }
};