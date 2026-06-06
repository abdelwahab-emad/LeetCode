class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int pre = 0, suf = 0, n = nums.size();
        vector<int> ans;
        for(int i = 0;i < n;i++) suf += nums[i];
        for(int i = 0;i < n;i++) {
            suf -= nums[i];
            ans.push_back(abs(pre - suf));
            pre += nums[i];
        } 
        return ans;
    }
};