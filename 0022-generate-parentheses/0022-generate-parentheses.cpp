class Solution {
    struct state {
        string str;
        int open, close;
    };

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        queue<state> q;
        q.push({"", 0, 0});
        while (!q.empty()) {
            state cur = q.front();
            q.pop();
            if (cur.str.size() == 2 * n) {
                ans.push_back(cur.str);
                continue;
            }
            if (cur.open < n) {
                q.push({cur.str + '(', cur.open + 1, cur.close});
            }
            if (cur.close < cur.open) {
                q.push({cur.str + ')', cur.open, cur.close + 1});
            }
        }
        return ans;
    }
};