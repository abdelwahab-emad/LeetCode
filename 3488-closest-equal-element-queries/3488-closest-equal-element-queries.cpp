class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        map<int, vector<int>> positions;
        for (int i = 0; i < n; ++i) {
            positions[nums[i]].push_back(i);
        }

        vector<int> answer;

        for (int idx : queries) {
            int val = nums[idx];
            const vector<int>& pos = positions[val];

            if (pos.size() <= 1) {
                answer.push_back(-1);
                continue;
            }

            auto it = lower_bound(pos.begin(), pos.end(), idx);
            int i = distance(pos.begin(), it);
            int m = pos.size();

            int prev_idx = pos[(i - 1 + m) % m];
            int next_idx = pos[(i + 1) % m];

            int dist1 = (idx - prev_idx + n) % n;
            int dist2 = (next_idx - idx + n) % n;

            answer.push_back(min(dist1, dist2));
        }

        return answer;
    }
};