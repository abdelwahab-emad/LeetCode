class Solution {
public:
    int dp[1001][1001];string ss;
        bool is_pal(int l, int r) {
	if (l >= r)return 1;
	int& ret = dp[l][r];
	if (~ret)return ret;
	return ret = ((ss[l] == ss[r]) && is_pal(l + 1, r - 1));
        }
    string longestPalindrome(string s) {
        ss = s;
        memset(dp,-1,sizeof(dp));
        int re = 1;string answer;
        answer+=ss[0];
        for(int i = 0;i<s.size();i++){
            string ans;ans+=s[i];
            for(int j = i+1;j<s.size();j++){
                ans+=s[j];
                if(is_pal(i,j)==1)
                {
                    re = max(re,(j-i+1));
                    if(re == j-i+1)answer = ans;
                }
            }
        }
       return answer;
    }            

};