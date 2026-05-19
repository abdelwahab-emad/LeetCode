class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0;
        while (i < n and j < m) {
            while(i < n and nums1[i] < nums2[j])i++;
            if (i < n and nums1[i] == nums2[j]) {
                return nums1[i];
            }
            j++;
        }   
        return -1;
    }
};