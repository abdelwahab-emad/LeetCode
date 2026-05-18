class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        map<int, vector<int>> mp;
        for(int i = 0;i < n;i++) {
            mp[arr[i]].push_back(i);
        }
        queue<pair<int, int>> q;
        vector<int> vis(n, 0);
        q.push({0, 0});
        vis[0] = 1;
        while (!q.empty()){
            auto[cur, dis] = q.front();
            q.pop();
            if (cur == n - 1) {
                return dis;
            }
            if (cur - 1 >= 0 and !vis[cur - 1]) {
                vis[cur - 1] = 1;
                q.push({cur - 1, dis + 1});
            }
            if (cur + 1 < n and !vis[cur + 1]) {
                vis[cur + 1] = 1;
                q.push({cur + 1, dis + 1}); 
            }
            for(int idx : mp[arr[cur]]) {
                if (!vis[idx]) {
                    vis[idx] = 1;
                    q.push({idx, dis + 1});
                }
            }
            mp.erase(arr[cur]);
        }
        return -1;
    }
};