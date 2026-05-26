class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char, int> frq;
        for (auto c : word) frq[c]++;
        int ans = 0;
        for (char c = 'a'; c <= 'z';c++) {
            if (frq[c] and frq[toupper(c)]) ans++;
        }
        return ans;
    }
};