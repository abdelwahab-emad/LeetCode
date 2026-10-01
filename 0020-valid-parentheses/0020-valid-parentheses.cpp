class Solution {
public:
    bool isValid(string s) {
        stack<char> st1;
        for (auto c : s) {
            if (c == '(') {
                st1.push(c);
            } else if (c == ')') {
                if (st1.empty())
                    return false;
                if (st1.top() != '(')
                    return false;
                st1.pop();
            }
            if (c == '{') {
                st1.push(c);
            } else if (c == '}') {
                if (st1.empty())
                    return false;
                if (st1.top() != '{')
                    return false;
                st1.pop();
            }
            if (c == '[') {
                st1.push(c);
            } else if (c == ']') {
                if (st1.empty())
                    return false;
                if (st1.top() != '[')
                    return false;
                st1.pop();
            }
        }
        if (st1.size() > 0)
            return false;
        return true;
    }
};