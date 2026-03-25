class Solution {
public: 
    string a, b;
    vector<vector<int>> dp;
    vector<int>suf1, suf2;
    int go(int i, int j){
        if(i == a.size() and j == b.size()){
            return 0;
        }
        int &ret = dp[i][j];
        if(~ret)return ret;
        ret = 1e6;
        if(a[i] == b[j]){
            ret = min(ret, go(i + 1, j + 1));
        }
        else if(i < a.size() and j < b.size()){
            ret = min(ret, go(i + 1, j) + int(a[i]));
            ret = min(ret, go(i, j + 1) + int(b[j]));
        }
        else if(i < a.size()){
            ret = min(ret, go(a.size(), j) + suf1[i]);
        }
        else{
            ret = min(ret, go(i, b.size()) + suf2[j]);
        }
        return ret;
    }
    int minimumDeleteSum(string s1, string s2) {
        a = s1, b = s2;
        suf1 = vector<int>(a.size());
        suf2 = vector<int>(b.size());
        dp = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        suf1[a.size() - 1] = int(a.back());
        for(int i = a.size() - 2;i >= 0;i--)suf1[i] = suf1[i + 1] + int(a[i]);
        suf2[b.size() - 1] = int(b.back());
        for(int i = b.size() - 2;i >= 0;i--)suf2[i] = suf2[i + 1] + int(b[i]);
        return go(0, 0);
    }
};