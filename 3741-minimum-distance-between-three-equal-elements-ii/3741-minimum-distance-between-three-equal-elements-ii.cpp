class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = 1e8, n = nums.size();
        vector<int> nxt(n + 2, n + 2), lst(n + 2, n + 2);
        lst[nums[n - 1]] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            nxt[i] = lst[nums[i]];
            lst[nums[i]] = i;
            int j = nxt[i], k = -1;
            if (j < n) {
                k = nxt[j];
                if (k < n) {
                    int dis = abs(i - j) + abs(i - k) + abs(j - k);
                    ans = min(ans, dis);
                }
            }
        }
        return ans != 1e8 ? ans : -1;
    }
};