class Solution {
public:
    int mirrorDistance(int n) {
        int val = n, cur = 0;
        while(val > 0){
            cur = cur * 10 + val % 10;
            val /= 10;
        }
        return abs(n - cur);
    }
};