class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,float>>v(n);
        pair<int,float> p;
        for(int i=0 ; i<n ; i++) {
            p.first = position[i];
            p.second = speed[i];
            v[i] = p;
        }
        sort(v.begin(), v.end());
        stack<pair<int,float>> s;
        float t;
        for(int i= n-1; i>=0; i--) {
            t = (target - v[i].first)/v[i].second;
            if(!s.empty()) {
                if(t <= (target-s.top().first)/s.top().second) continue;
                else s.push(v[i]);
            } else {
                s.push(v[i]);
            }
        }
        return s.size();
    }
};