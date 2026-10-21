
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        string res;
        res.reserve(s.length()); // Pre-allocate memory for O(1) appends without reallocations
        
        int cycle_len = 2 * (numRows - 1);
        int n = s.length();

        for (int i = 0; i < numRows; ++i) {
            for (int j = i; j < n; j += cycle_len) {
                res.push_back(s[j]);

                // Add the diagonal character for middle rows
                if (i > 0 && i < numRows - 1) {
                    int diagonal_idx = j + cycle_len - 2 * i;
                    if (diagonal_idx < n) {
                        res.push_back(s[diagonal_idx]);
                    }
                }
            }
        }

        return res;
    }
};