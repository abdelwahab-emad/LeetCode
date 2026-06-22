class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int frq[26] = {};
        for (auto c : text) frq[c - 'a']++;
        string s = "balloon";
        int cnt = 0;
        while (true) {
            bool f = 1;
            for (auto c : s) {
                if (frq[c - 'a'] == 0) {
                    f = 0;
                    break;
                }
                frq[c - 'a']--;
            }
            if (f) cnt++;
            else break;
        }
        return cnt;
    }
};