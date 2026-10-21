#include <vector>
#include <string>

class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = colors.length();
        int d[128];
        d['W'] = 0;
        d['R'] = 1;
        d['B'] = 2;
        
        vector<int> ins(n, 0);
        vector<int> outs(n, 0);
        
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            int uc = d[colors[u]];
            int vc = d[colors[v]];
            
            if (uc == vc) {
                return -1;
            }
            
            if ((uc + 1) % 3 == vc) {
                if (ins[v] > 0 || outs[u] >= 2) return -1;
                ins[v]++;
                outs[u]++;
            } else if ((vc + 1) % 3 == uc) {
                if (ins[u] > 0 || outs[v] >= 2) return -1;
                ins[u]++;
                outs[v]++;
            } else {
                return -1;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (ins[i] == 0 && outs[i] <= 2) {
                return i;
            }
        }
        
        return -1;
    }
};