class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, INT_MAX / 2);
        dp[0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            int cost_i = costs[i - 1];
            for (int j = max(0, i - 3); j < i; ++j) {
                dp[i] = min(dp[i], dp[j] + cost_i + (i - j) * (i - j));
            }
        }
        
        return dp[n];
    }
};