class Solution {
public:
    int minPartitions(string n) {
        int mx = 0;
        for(auto c : n){
            int x = c - '0';
            mx = max(mx, x);
        }
        return mx;
    }
};