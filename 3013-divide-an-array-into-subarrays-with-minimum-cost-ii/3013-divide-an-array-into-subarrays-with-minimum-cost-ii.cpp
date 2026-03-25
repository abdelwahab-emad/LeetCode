class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long ans = LLONG_MAX;
        long long sum = 0;
        multiset<int> low, high;
        
        auto add = [&] (int val){
            low.insert(val);
            sum += val;
            if(low.size() > k - 2){
                int last = *low.rbegin();
                sum -= last;
                low.erase(prev(low.end()));
                high.insert(last);
            }
        };

        auto remove = [&](int val){
            auto it = low.find(val);
            if(it != low.end()){
                sum -= val;
                low.erase(it);
                if(!high.empty()){
                    int first = *high.begin();
                    high.erase(high.begin());
                    low.insert(first);
                    sum += first;
                }
            }else{
                auto it_high = high.find(val);
                if (it_high != high.end()) {
                    high.erase(it_high);
                }
            }
        };
        for(int j = 2;j <= min((int)nums.size() - 1, dist + 1);j++){
            add(nums[j]);
        }

        ans = nums[0] + nums[1] + sum;

        for(int i = 2;i < nums.size();i++){

            remove(nums[i]);
            if(i + dist < nums.size()){
                add(nums[i + dist]);
            }

            if(low.size() == k - 2){
                ans = min(ans, nums[0] + nums[i] + sum);
            }
        }

        return ans;
    }
};