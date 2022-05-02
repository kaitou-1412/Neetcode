class LRUCache {
public:
    unordered_map<int, pair<list<int>::iterator, int> > m;
    list<int> p;
    int l;
    LRUCache(int capacity) {
        l = capacity;
        m.clear(), p.clear();
    }
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        if(m[key].first == p.end()) return -1;
        p.erase(m[key].first);
        p.push_back(key);
        m[key].first = (--p.end());
        return m[key].second;
    }
    void put(int key, int value) {
        if(m.find(key) == m.end() || m[key].first == p.end()) {
            if(p.size() == l) {
                list<int>::iterator it = m[p.front()].first;
                m[p.front()].first = p.end();
                p.pop_front();
            }
        } else {
            list<int>::iterator it = m[key].first;
            p.erase(it);
        }
        p.push_back(key);
        m[key].first = (--p.end());
        m[key].second = value;
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */