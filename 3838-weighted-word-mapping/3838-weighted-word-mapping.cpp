class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string re = "";
        for (auto s : words) {
            int sum = 0;
            for(auto c : s) {
                sum += weights[c - 'a'];
            }
            sum %= 26;
            re += 'z' - sum;
        }
        return re;
    }
};