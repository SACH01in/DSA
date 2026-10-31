#include <vector>

class Solution {
public:
    int uniquePaths(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 0 || n == 0) return 0;
        
        long long MOD = 1000000007;
        std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(2, 0));
        dp[1][0] = 1;
        dp[1][1] = 1;
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    long long t0 = dp[c+1][1];
                    long long t1 = dp[c][0];
                    dp[c+1][0] = t0;
                    dp[c+1][1] = t1;
                } else {
                    long long val = (dp[c+1][1] + dp[c][0]) % MOD;
                    dp[c+1][0] = val;
                    dp[c+1][1] = val;
                }
            }
        }
        return dp[n][0];
    }
};