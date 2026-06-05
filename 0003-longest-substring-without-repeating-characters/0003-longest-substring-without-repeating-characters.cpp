class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, n = s.size();
        for(int i = 0;i < n;i++) {
            map<int, int> frq;
            int cnt = 0, j = i;
            while (j < n and frq[s[j] - 'a'] == 0) {
                frq[s[j] - 'a']++;
                cnt++;
                j++;
            } 
            ans = max(ans, cnt);
        }
        return ans;
    }
};