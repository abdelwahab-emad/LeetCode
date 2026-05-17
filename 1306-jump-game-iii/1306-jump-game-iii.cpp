class Solution {
public:
    bool dfs(vector<int>& v, int idx, vector<int>&vis) {
        if (idx < 0 or idx >= v.size()) return false;
        if (vis[idx]) return false;
        if (v[idx] == 0) return true;

        vis[idx] = 1;
        return (dfs(v, idx + v[idx], vis)) or (dfs(v, idx - v[idx], vis));
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size(), 0);
        return dfs(arr, start, vis);
    }
};