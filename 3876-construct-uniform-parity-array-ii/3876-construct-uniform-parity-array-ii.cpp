class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // if want all odds if num even and is the min element : false
        bool f = 0;
        int mi = 1e9;
        for (int i = 0;i < nums1.size();i++) {
            if (nums1[i] % 2 != 0) f = 1;
            mi = min(mi, nums1[i]);
        }
        if (!f) return true;
        if (f and (mi % 2 != 0)) return true;
        return false; 
    }
};