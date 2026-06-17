class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> len(n + 1, 0);
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '*') len[i+1] = len[i] > 0 ? len[i] - 1 : 0;
            else if (c == '#') len[i+1] = len[i] * 2;
            else if (c == '%') len[i+1] = len[i];
            else len[i+1] = len[i] + 1;
        }
        if (k >= len[n]) return '.';
        long long pos = k;
        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            long long before = len[i];
            if (c == '#') {
                pos = before > 0 ? pos % before : 0;
            } else if (c == '%') {
                pos = before - 1 - pos;
            } else {
                if (pos == before) return c;
            }
        }
        return '.';
    }
};