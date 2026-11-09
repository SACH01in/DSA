class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy_servers;
        vector<int> request_count(k, 0);
        
        for (int i = 0; i < arrival.size(); ++i) {
            long long curr_time = arrival[i];
            long long duration = load[i];
            
            while (!busy_servers.empty() && busy_servers.top().first <= curr_time) {
                available.insert(busy_servers.top().second);
                busy_servers.pop();
            }
            
            if (available.empty()) {
                continue;
            }
            
            int start = i % k;
            auto it = available.lower_bound(start);
            if (it == available.end()) {
                it = available.begin();
            }
            
            int server_id = *it;
            available.erase(it);
            
            busy_servers.push({curr_time + duration, server_id});
            request_count[server_id]++;
        }
        
        int max_requests = 0;
        for (int count : request_count) {
            max_requests = max(max_requests, count);
        }
        
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (request_count[i] == max_requests) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};