class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,long long>>> adj(n);
        vector<int> indeg(n, 0);
        vector<long long> costs;
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            long long c = e[2];
            adj[u].push_back({v, c});
            indeg[v]++;
            costs.push_back(c);
        }
        vector<int> topo;
        vector<int> indeg2 = indeg;
        queue<int> q;
        for (int i = 0; i < n; i++) if (indeg2[i] == 0) q.push(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            topo.push_back(u);
            for (auto &pr : adj[u]) {
                if (--indeg2[pr.first] == 0) q.push(pr.first);
            }
        }
        sort(costs.begin(), costs.end());
        costs.erase(unique(costs.begin(), costs.end()), costs.end());
        auto feasible = [&](long long threshold) -> bool {
            vector<long long> dist(n, LLONG_MAX);
            dist[0] = 0;
            for (int u : topo) {
                if (dist[u] == LLONG_MAX) continue;
                if (!online[u]) continue;
                for (auto &pr : adj[u]) {
                    int v = pr.first;
                    long long c = pr.second;
                    if (c < threshold) continue;
                    if (!online[v]) continue;
                    if (dist[u] + c < dist[v]) dist[v] = dist[u] + c;
                }
            }
            return dist[n-1] <= k;
        };
        int lo = 0, hi = (int)costs.size() - 1, ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (feasible(costs[mid])) {
                ans = costs[mid];
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};