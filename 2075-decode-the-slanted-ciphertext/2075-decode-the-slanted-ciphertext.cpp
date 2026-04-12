class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.length();
        int cols = n / rows;
        string res;
        for (int j = 0; j < cols; ++j) {
            for (int r = 0, c = j; r < rows && c < cols; ++r, ++c) {
                res += encodedText[r * cols + c];
            }
        }
        while (!res.empty() && res.back() == ' ') {
            res.pop_back();
        }
        
        return res;
    }
};