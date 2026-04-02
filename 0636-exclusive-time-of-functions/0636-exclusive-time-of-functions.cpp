class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> st;
        int prevTime = 0;
        for (auto &log : logs) {
            int id = 0, time = 0;
            char type;        
            int i = 0;
            while (log[i] != ':') id = id * 10 + (log[i++] - '0');
            i++;
            type = log[i];
            while (log[i] != ':') i++;
            i++;
            while (i < log.size()) time = time * 10 + (log[i++] - '0');
            if (type == 's') {
                if (!st.empty()) ans[st.top()] += time - prevTime;
                st.push(id);
                prevTime = time;
            } else {
                ans[st.top()] += time - prevTime + 1;
                st.pop();
                prevTime = time + 1;
            }
        }
        return ans;
    }
};