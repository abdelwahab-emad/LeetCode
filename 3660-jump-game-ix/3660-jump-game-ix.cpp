class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        struct node {
            int v, l, r;
        };
        vector<node> s;
        for (int i = 0; i < n; i++) {
            int v = nums[i], l = i, r = i;
            while (!s.empty() && s.back().v > nums[i]) {
                node ls = s.back();
                s.pop_back();
                v = max(v, ls.v);
                l = ls.l;
            }
            s.push_back({v, l, r});
        }
        for (auto& ans : s) {
            for (int i = ans.l; i <= ans.r; i++) {
                res[i] = ans.v;
            }
        }
        return res;
    }
};