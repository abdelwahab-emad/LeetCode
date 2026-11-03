class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int cnt = 0;
        for (auto val : nums) cnt += abs(val - mx);
        return cnt;
    }
};