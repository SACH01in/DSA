#include <string>
#include <vector>

class Solution {
public:
    int distinctSubseqII(std::string s) {
        long long MOD = 1e9 + 7;
        std::vector<long long> dp(26, 0);
        long long total = 0;
        
        for (char c : s) {
            int idx = c - 'a';
            long long added = (total + 1 - dp[idx] + MOD) % MOD;
            total = (total + added) % MOD;
            dp[idx] = (dp[idx] + added) % MOD;
        }
        
        return total;
    }
};