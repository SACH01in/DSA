class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if (value == 1) return -1;
        long long p = value;
        for (long long i = 2; i * i <= value; i++) {
            if (value % i == 0) {
                p = i;
                break;
            }
        }
        if (value - p + 2 <= 2LL * index) return -1;
        if (index == n - 1) return value;
        return value + p - 2 + 2LL * (n - 1 - index);
    }
};