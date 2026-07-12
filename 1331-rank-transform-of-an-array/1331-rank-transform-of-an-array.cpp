class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;
        auto v = arr;
        vector<int> ans = {};
        sort(v.begin(), v.end());
        int id = 1;
        if (v.empty()) return ans;
        mp[v[0]] = id;
        for (int i = 1;i < v.size();i++){
            if (v[i] != v[i - 1])id++;
             mp[v[i]] = id;
        }
        for (int i = 0;i < arr.size();i++) ans.push_back(mp[arr[i]]);
        return ans;
    }
};