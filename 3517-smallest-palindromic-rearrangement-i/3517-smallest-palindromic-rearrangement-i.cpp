class Solution {
public:
    string smallestPalindrome(string s) {
        int frq[26]{};
        for (auto c : s) frq[c - 'a']++;
        string re;
        char c = '.';
        for (int i = 0;i < 26;i++) {
            if (frq[i] == 0) continue;
            if (frq[i] % 2 == 1) {
                c = char(i + 'a');
                frq[i]--;
            }
            int cnt = frq[i] / 2;
            while (cnt--) {
                re += char(i + 'a');
            }
        }
        string t = re;
        reverse(t.begin(), t.end());
        if (c != '.') re += c;
        re += t;
        return re;
    }
};