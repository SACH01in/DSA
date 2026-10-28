class TimeMap {
    unordered_map<string, vector<pair<int, string>>> map;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        map[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if (map.find(key) == map.end()) {
            return "";
        }
        const auto& vec = map[key];
        int left = 0;
        int right = (int)vec.size() - 1;
        int ans = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (vec[mid].first <= timestamp) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        if (ans == -1) {
            return "";
        }
        return vec[ans].second;
    }
};