class Solution {
public:
    const int N = 500 + 10;
    vector<vector<vector<int>>>dp;
    vector<int>a, b;
    int solve(int i, int j, int take){
        if(i == a.size() or j == b.size()){
            if(take == 1)return 0;
            return -1e9;
        }
        int &ret = dp[i][j][take];
        if(~ret)return ret;
        ret = -1e9;
        ret = max(ret, solve(i + 1, j, take));
        //cout << ret << endl;
        ret = max(ret, solve(i, j + 1, take));
       // cout << ret << endl;
        ret = max(ret, solve(i + 1, j + 1, 1) + (a[i] * b[j]));
     //   cout << ret << endl;
        return ret;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        a = nums1;
        b = nums2;
        dp = vector<vector<vector<int>>>(nums1.size() + 1, 
        vector<vector<int>>(nums2.size() + 2, vector<int>(2, -1)));
        return solve(0, 0, 0);
    }
};