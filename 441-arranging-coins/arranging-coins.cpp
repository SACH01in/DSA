class Solution {
public:
    int arrangeCoins(int n) {
        long long left = 0;
        long long right = n;
        long long ans = 0;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long coins = mid * (mid + 1) / 2;
            
            if (coins <= n) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return ans;
    }
};