class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int ans = 0, l = 0, r = 0;
        for(auto &c : moves) {
            if(c == 'L')l++;
            else if(c == 'R')r++;
            else ans++;
        }
        ans += abs(l - r);
        return ans;
    }
};