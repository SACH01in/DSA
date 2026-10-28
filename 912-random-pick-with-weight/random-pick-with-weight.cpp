class Solution {
private:
    vector<int> prefix_sums;
    int total_sum;
    mt19937 rng;
    uniform_int_distribution<int> dist;

public:
    Solution(vector<int>& w) {
        int n = w.size();
        prefix_sums.resize(n);
        int current_sum = 0;
        for (int i = 0; i < n; ++i) {
            current_sum += w[i];
            prefix_sums[i] = current_sum;
        }
        total_sum = current_sum;
        rng.seed(random_device{}());
        dist = uniform_int_distribution<int>(1, total_sum);
    }
    
    int pickIndex() {
        int target = dist(rng);
        auto it = lower_bound(prefix_sums.begin(), prefix_sums.end(), target);
        return distance(prefix_sums.begin(), it);
    }
};