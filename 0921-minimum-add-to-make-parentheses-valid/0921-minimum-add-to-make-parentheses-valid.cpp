class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        stack<char> st;
        for (auto c : s) {
            if (c == '(') {
                st.push(c);
            } else {
                if (st.empty()) ans++;
                else st.pop();
            }
        }
        return ans + (int)st.size();
    }
};