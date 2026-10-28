class Solution {
public:
    bool isPerfectSquare(int num) {
        long long left = 1;
        long long right = num;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long sq = mid * mid;
            
            if (sq == num) {
                return true;
            } else if (sq < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};