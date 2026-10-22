class Solution {
public:
    int longestValidParentheses(std::string s) {
        int left = 0, right = 0, maxLength = 0;
        
        for (char c : s) {
            if (c == '(') {
                left++;
            } else {
                right++;
            }
            if (right == left) {
                maxLength = std::max(maxLength, 2 * right);
            } else if (right > left) {
                left = 0;
                right = 0;
            }
        }
        
        left = 0;
        right = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxLength = std::max(maxLength, 2 * left);
            } else if (left > right) {
                left = 0;
                right = 0;
            }
        }
        
        return maxLength;
    }
};