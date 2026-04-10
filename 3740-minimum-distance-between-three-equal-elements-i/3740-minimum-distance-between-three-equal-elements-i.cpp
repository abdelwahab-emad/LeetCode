class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = 1e8;
        for(int i = 0;i < nums.size();i++){
            for(int j = i + 1;j < nums.size();j++){
                for(int k = j + 1;k < nums.size();k++){
                    if(nums[i] == nums[j] && nums[i] == nums[k]){
                       int dis = abs(i - j) + abs(i - k) + abs(j - k);
                       ans = min(ans, dis);
                    }
                }
            }
        }
        return ans != 1e8 ? ans : -1;
    }
};