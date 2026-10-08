class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int cnt = 0;
        for (char c : s) {
            if (c == '(') {
                if (cnt > 0) {
                    res += c;
                }
                cnt++;
            } else {
                cnt--;
                if (cnt > 0) {
                    res += c;
                }
            }
        }
        return res;
    }
};