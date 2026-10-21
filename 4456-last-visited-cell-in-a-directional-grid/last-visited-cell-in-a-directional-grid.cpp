#include <vector>

class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<bool> visited(m * n, false);
        int r = 0, c = 0;
        visited[0] = true;
        
        int last_r = 0, last_c = 0;
        
        while (true) {
            last_r = r;
            last_c = c;
            
            char dir = grid[r][c];
            int nr = r, nc = c;
            
            if (dir == 'L') nc--;
            else if (dir == 'R') nc++;
            else if (dir == 'U') nr--;
            else if (dir == 'D') nr++;
            
            if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr * n + nc]) {
                break;
            }
            
            r = nr;
            c = nc;
            visited[r * n + c] = true;
        }
        
        return {last_r, last_c};
    }
};