class TimeMap {
public:
    unordered_map <string, vector <pair <int, string> > > Map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        Map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int start = 0, end = Map[key].size() - 1;
        int mid;
        string res = "";
        while(start <= end) {
            mid = start + (end-start)/2;
            if(Map[key][mid].first <= timestamp) {
                res = Map[key][mid].second;
                start = mid+1;
            } else end = mid-1;
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */