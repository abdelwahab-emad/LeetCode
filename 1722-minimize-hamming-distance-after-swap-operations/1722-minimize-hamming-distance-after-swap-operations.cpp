
class Solution {
public:
     vector<int> parent, r;
     int find(int x){
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
     }
     void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b)return;
        if(r[a] < r[b])parent[a] = b;
        else if(r[a] > r[b])parent[b] = a;
        else {
            parent[b] = a;
            r[a]++;
        }
     }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        r.assign(n, 0);
        for(int i = 0;i < n;i++) parent[i] = i;
        for(auto &e : allowedSwaps)merge(e[0], e[1]);

        map<int, vector<int>> comp;
        for(int i = 0;i < n;i++) comp[find(i)].push_back(i);

        int ans = 0;
        for(auto &p : comp) {
            map<int, int> cnt;
            for(auto idx : p.second) cnt[source[idx]]++;
            for(auto idx : p.second) {
                if(cnt[target[idx]] > 0) cnt[target[idx]]--;
                else ans++;
            }
        }
        return ans;
    }
};