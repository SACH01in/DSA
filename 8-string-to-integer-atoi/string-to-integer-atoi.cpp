class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length(), sign = 1;
        long long result = 0;
        
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        if (i < n) {
            if (s[i] == '-') {
                sign = -1;
                i++;
            } else if (s[i] == '+') {
                i++;
            }
        }
        
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            result = result * 10 + (s[i] - '0');
            
            if (result * sign > INT_MAX) return INT_MAX;
            if (result * sign < INT_MIN) return INT_MIN;
            
            i++;
        }
        
        return result * sign;
    }
};