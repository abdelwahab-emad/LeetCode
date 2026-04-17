class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        map<int, int> m;
        int n = nums.size();
        vector<int> idx(n);
        idx[n - 1] = n;
        m[nums[n - 1]] = n - 1;
        int ans = 1e9;
        for(int i = n - 2;i >= 0;i--){
            int val = nums[i], rev = 0;
            while(val > 0){
                rev = (rev * 10 + val % 10);
                val /= 10;
            }
            if(m.find(rev) != m.end()) {
                idx[i] = m[rev];
            } else {
                idx[i] = n;
            }
            m[nums[i]] = i;
            if(idx[i] != n){
                ans = min(ans, abs(i - idx[i]));
            }
        }
        if(ans == 1e9)ans = -1;
        return ans;
    }
};