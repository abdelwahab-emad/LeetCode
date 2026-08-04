class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mx = 0, mi = 1000000;
        vector<bool> vis(mi);
        for (auto &v : nums) {
            vis[v] = true;
            mx = max(mx, v);
            mi = min(mi, v);
        }
        vector<int> ans;
        for (int i = mi;i <= mx;i++) {
            if (!vis[i]) ans.push_back(i);
        }
        return ans;
    }
};