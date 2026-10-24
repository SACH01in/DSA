#include <string>

class Solution {
public:
    bool isNumber(std::string s) {
        int i = 0, n = s.length();
        if (n == 0) return false;
        
        if (s[i] == '+' || s[i] == '-') i++;
        
        int countDigits = 0;
        
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            i++;
            countDigits++;
        }
        
        if (i < n && s[i] == '.') {
            i++;
            while (i < n && s[i] >= '0' && s[i] <= '9') {
                i++;
                countDigits++;
            }
        }
        
        if (countDigits > 0 && i < n && (s[i] == 'e' || s[i] == 'E')) {
            i++;
            if (i < n && (s[i] == '+' || s[i] == '-')) i++;
            int expDigits = 0;
            while (i < n && s[i] >= '0' && s[i] <= '9') {
                i++;
                expDigits++;
            }
            if (expDigits == 0) return false;
        }
        
        return i == n && countDigits > 0;
    }
};