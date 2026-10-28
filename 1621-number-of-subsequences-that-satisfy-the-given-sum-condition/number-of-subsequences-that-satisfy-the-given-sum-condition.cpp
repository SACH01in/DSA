class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mod = 1e9 + 7;
        
        vector<int> pows(n, 1);
        for (int i = 1; i < n; ++i) {
            pows[i] = (pows[i - 1] * 2) % mod;
        }
        
        int left = 0;
        int right = n - 1;
        long long count = 0;
        
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                count = (count + pows[right - left]) % mod;
                left++;
            } else {
                right--;
            }
        }
        
        return count;
    }
};