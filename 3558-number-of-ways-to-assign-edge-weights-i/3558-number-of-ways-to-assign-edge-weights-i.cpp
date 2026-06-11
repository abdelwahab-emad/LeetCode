class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        queue<pair<int,int>> q;
        q.push({1, 0});
        vector<int> vis(n + 1, 0);
        vis[1] = 1;
        int mx = 0;
        while (!q.empty()) {
            auto [u, d] = q.front();
            q.pop();
            mx = max(mx, d);
            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push({v, d + 1});
                }
            }
        }
        return modPow(2, mx - 1);
    }
};