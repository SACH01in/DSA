class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = ranges::min(nums);
        int moves = 0;
        for (int num : nums) {
            moves += (num - mn);
        }
        return moves;
    }
};