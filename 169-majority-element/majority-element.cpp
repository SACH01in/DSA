class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1, result = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == result){
                count += 1;
            } else if (nums[i] != result && count > 0){
                count -= 1;
            } else if(nums[i] != result && count == 0){
                result = nums[i];
                count += 1;
            }
        }
        return result;       
    }
};