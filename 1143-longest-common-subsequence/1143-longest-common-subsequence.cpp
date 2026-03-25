class Solution {
public:
    int n,m;
    string s,t;
    int dp[1001][1001];
    int solve(int i , int j){
        if(i >= n or j >= m)return 0;
        int & ret = dp[i][j];
        if(~ret)return ret;
        if(s[i] == t[j]){
            ret = max(ret,1 + solve(i+1,j+1));
        }        
        else{
            ret = max(ret,solve(i+1,j));
            ret = max(ret,solve(i,j+1));
        }
        return ret;
    }
    int longestCommonSubsequence(string text1, string text2) {
        n = int(text1.size());
        m = int(text2.size());
        s = text1;
        t = text2;
        memset(dp,-1,sizeof dp);
        return solve(0,0);
    }
};