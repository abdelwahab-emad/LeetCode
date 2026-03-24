#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        
        for (int i = 0; i < nums.size(); ++i) {
            int val = target - nums[i];
            
            if (mp.find(val) != mp.end()) {
                return {mp[val], i};
            }
            
            mp[nums[i]] = i;
        }
        
        return {};
    }
};