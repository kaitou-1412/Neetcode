class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int> > > pq;
        vector<vector<int>> res;
        for(int i=0; i<points.size(); i++) {
            pq.push({points[i][0] * points[i][0] + points[i][1]*points[i][1],{points[i][0], points[i][1]}});
            if(pq.size() > k) pq.pop();
        }
        while(pq.size() != 0) {
            res.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return res;
    }
};