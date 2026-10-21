class Solution {
public:
    int minSelection(vector<vector<int>>& availableIntervals, vector<vector<int>>& targetIntervals) {
        sort(targetIntervals.begin(), targetIntervals.end());
        vector<vector<int>> merged;
        for (auto& iv : targetIntervals) {
            if (merged.empty() || merged.back()[1] < iv[0]) merged.push_back(iv);
            else merged.back()[1] = max(merged.back()[1], iv[1]);
        }

        sort(availableIntervals.begin(), availableIntervals.end());

        int ans = 0, i = 0, n = availableIntervals.size();
        long long best = LLONG_MIN;
        long long reach = LLONG_MIN;

        for (auto& t : merged) {
            long long L = t[0], R = t[1];
            long long cur = L;

            if (reach < L) {
                
                while (i < n && availableIntervals[i][0] <= L) {
                    best = max(best, (long long)availableIntervals[i][1]);
                    i++;
                }
                if (best < L) return -1;
                ans++;
                reach = best;
            }
            cur = max(cur, reach);

            while (cur < R) {
                while (i < n && availableIntervals[i][0] <= cur) {
                    best = max(best, (long long)availableIntervals[i][1]);
                    i++;
                }
                if (best <= cur) return -1;
                ans++;
                reach = best;
                cur = best;
            }
        }
        return ans;
    }
};