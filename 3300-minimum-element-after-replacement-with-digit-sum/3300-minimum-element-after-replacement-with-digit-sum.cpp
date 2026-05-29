class Solution {
public:
    int minElement(vector<int>& nums) {
        int mi = 1e9;
        for (auto val : nums) {
            int sum = 0;
            while (val > 0) {
                sum += (val % 10);
                val /= 10;
            }
            mi = min(mi, sum);
        }
        return mi;
    }
};