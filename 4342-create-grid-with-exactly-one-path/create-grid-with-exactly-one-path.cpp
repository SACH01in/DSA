#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> createGrid(int m, int n) {
        std::vector<std::string> grid(m, std::string(n, '#'));
        
        grid[0] = std::string(n, '.');
        
        for (int i = 0; i < m; ++i) {
            grid[i][n - 1] = '.';
        }
        
        return grid;
    }
};