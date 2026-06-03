class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        long long ans = LLONG_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();
        vector<pair<int,int>> water(m);
        for (int i = 0; i < m; i++) water[i] = {waterStartTime[i], waterDuration[i]};
        sort(water.begin(), water.end());
        vector<int> ws(m);
        vector<long long> prefMinDurW(m), suffMinOpenW(m);
        for (int i = 0; i < m; i++) {
            ws[i] = water[i].first;
            prefMinDurW[i] = water[i].second;
            if (i) prefMinDurW[i] = min(prefMinDurW[i], prefMinDurW[i - 1]);
        }
        for (int i = m - 1; i >= 0; i--) {
            suffMinOpenW[i] = 1LL * water[i].first + water[i].second;
            if (i + 1 < m) suffMinOpenW[i] = min(suffMinOpenW[i], suffMinOpenW[i + 1]);
        }
        for (int i = 0; i < n; i++) {
            long long eL = 1LL * landStartTime[i] + landDuration[i];
            int k = upper_bound(ws.begin(), ws.end(), (int)eL) - ws.begin();
            if (k > 0) ans = min(ans, eL + prefMinDurW[k - 1]);
            if (k < m) ans = min(ans, suffMinOpenW[k]);
        }
        vector<pair<int,int>> land(n);
        for (int i = 0; i < n; i++) land[i] = {landStartTime[i], landDuration[i]};
        sort(land.begin(), land.end());
        vector<int> ls(n);
        vector<long long> prefMinDurL(n), suffMinOpenL(n);
        for (int i = 0; i < n; i++) {
            ls[i] = land[i].first;
            prefMinDurL[i] = land[i].second;
            if (i) prefMinDurL[i] = min(prefMinDurL[i], prefMinDurL[i - 1]);
        }

        for (int i = n - 1; i >= 0; i--) {
            suffMinOpenL[i] = 1LL * land[i].first + land[i].second;
            if (i + 1 < n) suffMinOpenL[i] = min(suffMinOpenL[i], suffMinOpenL[i + 1]);
        }
        for (int i = 0; i < m; i++) {
            long long eW = 1LL * waterStartTime[i] + waterDuration[i];
            int k = upper_bound(ls.begin(), ls.end(), (int)eW) - ls.begin();
            if (k > 0) ans = min(ans, eW + prefMinDurL[k - 1]);
            if (k < n) ans = min(ans, suffMinOpenL[k]);
        }
        return ans;
    }
};