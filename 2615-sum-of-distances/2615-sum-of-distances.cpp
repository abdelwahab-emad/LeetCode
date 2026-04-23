class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(n, 0);
        for (auto& p : mp) {
            auto v = p.second;
            int m = v.size();
            vector<long long> pref(m + 1, 0);
            for (int i = 0; i < m; i++) {
                pref[i + 1] = pref[i] + v[i];
            }
            for (int i = 0; i < m; i++) {
                long long left = (long long)i * v[i] - pref[i];
                long long right =
                    (pref[m] - pref[i + 1]) - (long long)(m - i - 1) * v[i];
                ans[v[i]] = left + right;
            }
        }
        return ans;
    }
};