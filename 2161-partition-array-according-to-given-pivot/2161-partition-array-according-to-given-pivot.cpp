class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>pre, mid, suf;
        for(int i = 0;i < nums.size();i++) {
            if (nums[i] < pivot) pre.push_back(nums[i]);
            else if (nums[i] > pivot) suf.push_back(nums[i]);
            else mid.push_back(nums[i]);
        }
        vector<int> ans;
        for(auto val : pre) ans.push_back(val);
        for(auto val : mid) ans.push_back(val);
        for(auto val : suf) ans.push_back(val);
        return ans;
    }
};