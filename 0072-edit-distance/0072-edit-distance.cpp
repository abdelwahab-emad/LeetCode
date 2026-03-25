class DP{
    public:
    vector<vector<int>>dp;
    vector<int>v;
    int n;
    string s, t;
    DP(string word1, string word2){
        s = word1, t = word2;
        dp = vector<vector<int>>(word1.size() + 1, vector<int>(word2.size() + 1, -1));
    }
    int solve(int i, int j){
        if(i == s.size() and j == t.size()){
            return 0;
        }
        int &ret = dp[i][j];
        if(~ret)return ret;
        ret = 10000;
        if(i < s.size() and j < t.size()){
            //already equal
            if(s[i] == t[j]){
                ret = min(ret, solve(i + 1, j + 1));
            }

            
            //replace 
            ret = min(ret, 1 + solve(i + 1, j + 1));

            //delete
            ret = min(ret, 1 + solve(i + 1, j));

            //insert
            ret = min(ret, 1 + solve(i, j + 1));
        }
        else if(i < s.size()){
            ret = min(ret, ((int)s.size() - i) + solve(s.size(), j));
        }
        else{
            ret = min(ret, ((int)t.size() - j) + solve(i, t.size()));
        }
        return ret;
    }
};
class Solution {
public:
    int minDistance(string word1, string word2) {
        DP dp(word1, word2);
        return dp.solve(0, 0);      
    }
};