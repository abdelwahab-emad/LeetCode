class Solution {
public:
    static const int MOD = 1e9 + 7;
    int LOG;
    vector<vector<int>> up, adj;
    vector<int> depth;
    vector<long long> p2;
    void dfs(int u, int p) {
        up[u][0] = p;
        for (int j = 1; j < LOG; j++) {
            up[u][j] = up[up[u][j - 1]][j - 1];
        }
        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        int d = depth[a] - depth[b];
        for (int j = 0; j < LOG; j++) {
            if (d & (1 << j)) a = up[a][j];
        }
        if (a == b) return a;
        for (int j = LOG - 1; j >= 0; j--) {
            if (up[a][j] != up[b][j]) {
                a = up[a][j];
                b = up[b][j];
            }
        }
        return up[a][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        LOG = 1;
        while ((1 << LOG) <= n) LOG++;
        adj.assign(n + 1, {});
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        up.assign(n + 1, vector<int>(LOG));
        depth.assign(n + 1, 0);
        dfs(1, 1);
        p2.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            p2[i] = (p2[i - 1] * 2) % MOD;
        }
        vector<int> ans;
        for (auto &q : queries) {
            int u = q[0], v = q[1];
            int L = lca(u, v);
            int dist = depth[u] + depth[v] - 2 * depth[L];

            if (dist == 0) ans.push_back(0);
            else ans.push_back((int)p2[dist - 1]);
        }
        return ans;
    }
};