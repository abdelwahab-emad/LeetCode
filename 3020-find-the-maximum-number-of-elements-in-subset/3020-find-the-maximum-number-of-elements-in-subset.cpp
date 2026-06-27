class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<long long, int> frq;
        int ones = 0;
        for (int x : nums) {
            if (x == 1) {
                ones++;
                continue;
            }
            frq[x]++;
        }
        int ans = (ones % 2 == 0 ? ones - 1 : ones);
        for (auto &[x, f] : frq) {
            long long cur = x;
            bool odd = 0;
            int res = 0;
            while (true) {
                int fr = frq[cur];
                if (fr > 1) {
                    res += 2;
                } else if (fr == 1) {
                    res++;
                    odd = 1;
                    break;
                } else {
                    break;
                }
                cur *= cur;
            }
            if (!odd) res--;
            ans = max(ans, res);
        }
        return ans;
    }
};