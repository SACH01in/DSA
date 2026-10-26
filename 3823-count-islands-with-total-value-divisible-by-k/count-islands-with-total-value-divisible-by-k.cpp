#pragma GCC optimize("O3", "unroll-loops")

#include <vector>
#include <queue>

class Solution {
public:
    int countIslands(std::vector<std::vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int island_count = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    long long island_sum = 0;
                    std::queue<std::pair<int, int>> q;
                    
                    q.push({i, j});
                    island_sum += grid[i][j];
                    grid[i][j] = 0;

                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();

                        for (int d = 0; d < 4; ++d) {
                            int nr = r + dr[d];
                            int nc = c + dc[d];

                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                                island_sum += grid[nr][nc];
                                grid[nr][nc] = 0; // Mark as visited
                                q.push({nr, nc});
                            }
                        }
                    }

                    if (island_sum % k == 0) {
                        island_count++;
                    }
                }
            }
        }

        return island_count;
    }
};