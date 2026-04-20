class Solution {
public:
    bool isPalindrome(int x) {
        string s;
        if (x < 0) {
            return false;
        }
        while (x > 0) {
            int digit = x % 10;
            s += char(digit + '0');
            x /= 10;
        }
        string t = s;
        reverse(t.begin(), t.end());
        return (s == t);
    }
};