class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int index = 0;
        unordered_map<string, vector<int> > mp;
        for(int i=0; i<strs.size(); i++) {
            string ogStr = strs[i];
            sort(strs[i].begin(), strs[i].end());
            mp[strs[i]].push_back(i);
            strs[i] = ogStr;
        }

        vector<vector<string> > res;
        vector<string> v;
        for(auto it: mp) {
            for(auto it2: it.second) {
                v.push_back(strs[it2]);
            }
            if(v.size()!=0) res.push_back(v);
            v.clear();
        }
        return res;
    }
};