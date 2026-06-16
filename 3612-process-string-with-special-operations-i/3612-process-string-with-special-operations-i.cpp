class Solution {
public:
    string processStr(string s) {
        string re = "";
        for (auto c : s) {
            if (c == '*') {
                if (!re.empty())
                    re.pop_back();
            } else if (c == '#') {
                re += re;
            } else if (c == '%') {
                reverse(re.begin(), re.end());
            } else {
                re += c;
            }
        }
        return re;
    }
};