class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
       sort(tasks.begin(), tasks.end(), [](vector<int>&a, vector<int>& b){
         return (a[1] - a[0]) > (b[1] - b[0]); 
       });

       int ans = 0;
       int cur = 0;
       for(auto &t : tasks){
        int actual = t[0], minimum = t[1];
        if (cur < minimum) {
            ans += (minimum - cur);
            cur = minimum;
        }
        cur -= actual;
       }
       return ans;
    }
};