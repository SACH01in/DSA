#include <vector>
#include <bitset>
#include <algorithm>

class Solution {
public:
    int minCost(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        std::vector<std::bitset<1024>> dp(n);
        
        for (int i = 0; i < m; ++i) {
            std::vector<std::bitset<1024>> next_dp(n);
            for (int j = 0; j < n; ++j) {
                std::bitset<1024> prev_xor;
                if (i > 0) prev_xor |= dp[j];
                if (j > 0) prev_xor |= next_dp[j - 1];
                
                if (i == 0 && j == 0) {
                    next_dp[j].set(grid[i][j]);
                } else {
                    int val = grid[i][j];
                    for (int x = 0; x < 1024; ++x) {
                        if (prev_xor.test(x)) {
                            next_dp[j].set(x ^ val);
                        }
                    }
                }
            }
            dp = std::move(next_dp);
        }
        
        for (int x = 0; x < 1024; ++x) {
            if (dp[n - 1].test(x)) {
                return x;
            }
        }
        return 0;
    }
};