#include <string>

class Solution {
public:
    bool isNumber(std::string s) {
        bool seenDigit = false;
        bool seenExponent = false;
        bool seenDot = false;
        int n = s.length();
        
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                seenDigit = true;
            } else if (c == '+' || c == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } else if (c == '.') {
                if (seenDot || seenExponent) {
                    return false;
                }
                seenDot = true;
            } else if (c == 'e' || c == 'E') {
                if (seenExponent || !seenDigit) {
                    return false;
                }
                seenExponent = true;
                seenDigit = false;
            } else {
                return false;
            }
        }
        
        return seenDigit;
    }
};
