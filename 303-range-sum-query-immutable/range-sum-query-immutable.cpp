class NumArray {
private:
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if (i == 0){
                prefix.push_back(nums[0]);
                continue;
            }
            prefix.push_back(nums[i] + prefix[prefix.size() - 1]);
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0){
            return prefix[right];
        }
        return prefix[right] - prefix[left -1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */