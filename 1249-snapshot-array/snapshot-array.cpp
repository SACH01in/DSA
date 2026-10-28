class SnapshotArray {
    int snap_cnt;
    vector<vector<pair<int, int>>> data;
public:
    SnapshotArray(int length) {
        snap_cnt = 0;
        data.resize(length);
        for (int i = 0; i < length; ++i) {
            data[i].reserve(4);
            data[i].emplace_back(0, 0);
        }
    }
    
    void set(int index, int val) {
        auto& vec = data[index];
        if (vec.back().first == snap_cnt) {
            vec.back().second = val;
        } else {
            vec.emplace_back(snap_cnt, val);
        }
    }
    
    int snap() {
        return snap_cnt++;
    }
    
    int get(int index, int snap_id) {
        const auto& vec = data[index];
        int left = 0;
        int right = (int)vec.size() - 1;
        
        if (vec[right].first <= snap_id) {
            return vec[right].second;
        }
        
        int ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (vec[mid].first <= snap_id) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return vec[ans].second;
    }
};