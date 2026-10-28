class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        int m = potions.size();
        vector<int> pairs(n);
        
        for (int i = 0; i < n; ++i) {
            long long min_potion = (success + spells[i] - 1) / spells[i];
            int left = 0;
            int right = m;
            
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (potions[mid] >= min_potion) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            
            pairs[i] = m - left;
        }
        
        return pairs;
    }
};