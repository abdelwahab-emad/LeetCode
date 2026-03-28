class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int l = 0, r = 0;
        int n = s.size();
        int ans = 0;
        while(r < n){
            while(r < n and st.find(s[r]) == st.end()){
                st.insert(s[r++]);
            }
            ans = max(ans, r - l);
            st.erase(s[l++]);
        }
        return ans;
    }
};