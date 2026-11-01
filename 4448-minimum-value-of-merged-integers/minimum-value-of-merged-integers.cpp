class Solution {
public:
    long long minMergedInteger(std::vector<int>& nums) {
        long long minVal = LLONG_MAX;
        
        for (size_t i = 0; i < nums.size(); i += 2) {
            long long merged = std::stoll(std::to_string(nums[i]) + std::to_string(nums[i + 1]));
            
            minVal = std::min(minVal, merged);
        }
        
        return minVal;
    }
};