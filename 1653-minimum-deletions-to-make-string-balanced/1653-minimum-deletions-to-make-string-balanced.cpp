class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0, cnt = 0;
        for(auto c : s){
            if(c == 'b')cnt++;
            else{
                ans = min(ans + 1, cnt);
            }
        }
        return ans;
    }
};