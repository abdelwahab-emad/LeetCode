class Solution {
public:
    long long mod = 2 * 1e9;
    long long add(long long a,long long b){
        return ((a % mod) + (b % mod)) % mod;
    }
    vector<vector<long long>>dp;
    long long solve(int i,int j,int m,int n){
        if(i == m - 1 and j == n -1)return 1;
        long long & ret = dp[i][j];
        if(~ret)return ret;
        ret = 0;
        if(i + 1 < m)
           ret = add(ret,solve(i + 1, j , m , n));
        if(j + 1 < n)
           ret = add(ret,solve(i, j + 1 , m , n));
           return ret;
    }
    int uniquePaths(int m, int n) {
    dp.assign(m, vector<long long>(n, -1));
        return solve(0,0,m,n);
    }
};