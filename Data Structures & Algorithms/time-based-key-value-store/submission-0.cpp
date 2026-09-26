class TimeMap {

private:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> values;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if (!values.contains(key)){
            values[key] = {{timestamp, value}};
        }
        else {
            // since time stamps increasing simply append to end
            values[key].push_back({timestamp, value});
        }
    }
    
    string get(string key, int timestamp) {
        // binary search thru the timestamps
        if (!values.contains(key)){
            return "";
        }

        int l = 0;
        int r = values[key].size() - 1;
        auto &items = values[key];
        while (l <= r){
            int c = (l + r) / 2;
            // 1,2,3,4,5 
            // ts = 4
            // 
            if (timestamp >= items[c].first){
                l = c + 1;
            }
            else{
                r = c - 1;
            }
        }
        if (r < 0){
            return "";
        }
        return items[r].second;
    }
};
