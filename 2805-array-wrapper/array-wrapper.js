class ArrayWrapper {
    constructor(nums) {
        this.nums = nums;
        this.sum = 0;
        for (let i = 0, len = nums.length; i < len; ++i) {
            this.sum += nums[i];
        }
    }

    valueOf() {
        return this.sum;
    }

    toString() {
        return `[${this.nums.join(',')}]`;
    }
}