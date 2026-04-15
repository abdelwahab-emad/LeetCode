class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int diff = abs(i - startIndex);
                int circularDiff = n - diff;
                int cur_dis = min(diff, circularDiff);

                if (ans == -1 || cur_dis < ans) {
                    ans = cur_dis;
                }
            }
        }

        return ans;
    }
};