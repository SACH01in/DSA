class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findBound(nums, target, true);
        if (first == -1) {
            return {-1, -1};
        }
        int last = findBound(nums, target, false);
        return {first, last};
    }

private:
    int findBound(vector<int>& nums, int target, bool isFirst) {
        int left = 0;
        int right = (int)nums.size() - 1;
        int ans = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                ans = mid;
                if (isFirst) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return ans;
    }
};