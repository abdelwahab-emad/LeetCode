class Solution {
  int lengthOfLongestSubstring(String s) {
    Set<String> st = {};
    int l = 0, r = 0;
    int n = s.length;
    int ans = 0;

    while (r < n) {
      while (r < n && !st.contains(s[r])) {
        st.add(s[r]);
        r++;
      }
      ans = (ans > (r - l)) ? ans : (r - l);
      st.remove(s[l]);
      l++;
    }

    return ans;
  }
}