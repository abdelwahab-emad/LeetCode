class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0, sum = 0;
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            if (digit == 0) continue;
            x = x * 10 + digit;
            sum += digit;
        }   
        string s = to_string(x);
        reverse(s.begin(), s.end());
        x = stoi(s);
        return x * sum;
    }
};