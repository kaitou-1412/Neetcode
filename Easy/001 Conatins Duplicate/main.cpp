class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
            if(m[nums[i]] > 1) return true;
        }
        return false;
        // set<int> s;
        // s.insert(nums.begin(), nums.end());
        // return s.size() < nums.size();
    }
};