class Solution {
public:
    static bool compare(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto num: nums) mp[num]++;
        vector<pair<int, int> > vec;
        copy(mp.begin(), mp.end(), back_inserter<vector<pair<int, int> > >(vec));
        sort(vec.begin(), vec.end(), compare);
        int count = 0;
        vector<int> res;
        for(auto it: vec) {
            if(count == k) break;
            res.push_back(it.first);
            count++;
        }
        return res;
    }
};