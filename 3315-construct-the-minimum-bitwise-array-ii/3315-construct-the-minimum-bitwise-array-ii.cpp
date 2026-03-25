class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(nums.size());
        
        for (int n : nums) {
            if (n == 2) {
                ans.push_back(-1);
            } else {
                int c = 0;
                while ((n >> c) & 1) {
                    c++;
                }
                ans.push_back(n - (1 << (c - 1)));
            }
        }
        return ans;
    }
};