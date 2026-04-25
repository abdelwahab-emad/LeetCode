class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<long long> points2;

        for (const auto& p : points) {
            int x = p[0], y = p[1];
            if (y == 0)
                points2.push_back(x);
            else if (x == side)
                points2.push_back((long long)side + y);
            else if (y == side)
                points2.push_back(2LL * side + (side - x));
            else if (x == 0)
                points2.push_back(3LL * side + (side - y));
        }

        sort(points2.begin(), points2.end());

        long long l = 1, h = 2LL * side;
        long long ans = 1;
        long long perimeter = 4LL * side;

        auto check = [&](long long mn) {
            for (int i = 0; i < n; ++i) {
                int count = 1;
                int curr = i;
                while (count < k) {
                    auto it = lower_bound(points2.begin(), points2.end(),
                                          points2[curr] + mn);
                    if (it == points2.end())
                        break;
                    int next_idx = distance(points2.begin(), it);
                    if (points2[i] + perimeter - points2[next_idx] < mn)
                        break;
                    count++;
                    curr = next_idx;
                }
                if (count == k)
                    return true;
            }
            return false;
        };

        while (l <= h) {
            long long mid = l + (h - l + 1) / 2;
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        return (int)ans;
    }
};