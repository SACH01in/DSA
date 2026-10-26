#pragma GCC optimize("O3", "unroll-loops")
#include <vector>
#include <string>

class Solution {
private:
    void backtrack(std::vector<std::string>& result, std::string& current, int open, int close, int n) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        if (open < n) {
            current.push_back('(');
            backtrack(result, current, open + 1, close, n);
            current.pop_back();
        }
        
        if (close < open) {
            current.push_back(')');
            backtrack(result, current, open, close + 1, n);
            current.pop_back();
        }
    }

public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string current;
        current.reserve(2 * n);
        backtrack(result, current, 0, 0, n);
        return result;
    }
};