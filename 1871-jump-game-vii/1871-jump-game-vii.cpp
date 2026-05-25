class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> dp(n, 0);
        dp[0] = 1;
        int cnt = 0;
        for(int i = 1;i < n;i++) {
            if (i - minJump >= 0 and dp[i - minJump]) {
                cnt++;
            }
            if (i - maxJump - 1 >= 0 and dp[i - maxJump - 1]) {
                cnt--;
            }
            dp[i] = (cnt > 0 and s[i] == '0');
        }
        return dp[n - 1];
    }
};