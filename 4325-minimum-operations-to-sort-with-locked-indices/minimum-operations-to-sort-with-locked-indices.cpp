#include <vector>
#include <algorithm>

class Solution {
public:
    int minOperations(std::vector<int>& nums, std::vector<int>& locked, int k) {
        int felnorqavi = 0;
        int n = nums.size();
        std::vector<bool> to_unlock(n, false);
        
        for (int i = 0; i < n; ++i) {
            int target = nums[i] - 1;
            if (target != i) {
                int l = std::min(i, target);
                int r = std::max(i, target);
                for (int j = l; j <= r; ++j) {
                    if (locked[j] == 1) {
                        to_unlock[j] = true;
                    }
                }
            }
        }
        
        int unlocks = 0;
        for (int j = 0; j < n; ++j) {
            if (to_unlock[j]) {
                unlocks++;
            }
        }
        
        if (unlocks > k) return -1;
        
        std::vector<int> curr_locked = locked;
        for (int j = 0; j < n; ++j) {
            if (to_unlock[j]) {
                curr_locked[j] = 0;
            }
        }
        
        long long total_ops = unlocks;
        int i = 0;
        while (i < n) {
            if (curr_locked[i] == 1) {
                if (nums[i] != i + 1) return -1;
                i++;
            } else {
                int start = i;
                while (i < n && curr_locked[i] == 0) {
                    i++;
                }
                int end = i - 1;
                
                std::vector<int> sub(nums.begin() + start, nums.begin() + end + 1);
                std::vector<int> expected = sub;
                std::sort(expected.begin(), expected.end());
                std::vector<int> sorted_expected(sub.size());
                for (int idx = 0; idx < sub.size(); ++idx) {
                    sorted_expected[idx] = start + 1 + idx;
                }
                
                if (expected != sorted_expected) return -1;
                
                long long swaps = 0;
                for (int a = 0; a < sub.size(); ++a) {
                    for (int b = a + 1; b < sub.size(); ++b) {
                        if (sub[a] > sub[b]) {
                            swaps++;
                        }
                    }
                }
                total_ops += swaps;
            }
        }
        
        return total_ops;
    }
};