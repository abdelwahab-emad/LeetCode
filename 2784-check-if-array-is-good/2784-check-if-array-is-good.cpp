class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cur = 1, n = nums.size();
        for(int i = 0;i < n - 1;i++) {
            if (nums[i] != cur) {
                return false;
            }
            cur++;
        }
        cur--;
        return cur == nums.back();
    }
};