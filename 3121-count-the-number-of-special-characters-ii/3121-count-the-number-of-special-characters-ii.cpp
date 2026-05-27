class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> frq1(26, -1), frq2(26, 1e8);
        for(int i = 0;i < word.size();i++) {
            if (islower(word[i])) {
                int idx = word[i] - 'a';
                frq1[idx] = max(frq1[idx], i);
            } else {
                int idx = word[i] - 'A';
                frq2[idx] = min(frq2[idx], i);
            }
        }
        int ans = 0;
        for(int i = 0;i < 26;i++) {
            if (frq1[i] == -1 or frq2[i] == 1e8) continue;
            if (frq1[i] < frq2[i]) ans++;
        }
        return ans;
    }
};