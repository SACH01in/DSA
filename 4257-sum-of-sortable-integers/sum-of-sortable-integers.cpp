class Solution {
public:
    long long sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefMax(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefMax[i + 1] = max(prefMax[i], nums[i]);
        }
        
        vector<int> suffMin(n + 1, 2e9);
        for (int i = n - 1; i >= 0; --i) {
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }
        
        vector<int> prefDrop(n, 0);
        for (int i = 1; i < n; ++i) {
            prefDrop[i] = prefDrop[i - 1] + (nums[i - 1] > nums[i] ? 1 : 0);
        }
        
        long long ans = 0;
        auto check = [&](int k) {
            for (int start = 0; start < n; start += k) {
                int end = start + k - 1;
                int drops = prefDrop[end] - prefDrop[start];
                if (nums[end] > nums[start]) {
                    ++drops;
                }
                if (drops > 1 || prefMax[start] > suffMin[start]) {
                    return false;
                }
            }
            return true;
        };
        
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                int other = n / i;
                if (check(i)) {
                    ans += i;
                }
                if (i != other && check(other)) {
                    ans += other;
                }
            }
        }
        
        return ans;
    }
};