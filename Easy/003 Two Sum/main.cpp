class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++) {
            if(mp[target - nums[i]] != 0) {
                res.push_back(i);
                res.push_back(mp[target - nums[i]] - 1);
                break;
            }
            mp[nums[i]] = i+1;
        }
        return res;
        
        // vector<int> res;
        // unordered_map<int, int> mp;
        // unordered_map<int, vector<int> > pos;
        // for(int i=0; i<nums.size(); i++) {
        //     mp[nums[i]] = 1;
        //     pos[nums[i]].push_back(i);
        // }
        // for(int i=0; i<nums.size(); i++) {
        //     if(mp[target - nums[i]] == 1) {
        //         if(target != 2*nums[i]) {
        //             res.push_back(pos[nums[i]][0]);
        //             res.push_back(pos[target - nums[i]][0]);
        //             break;
        //         }
        //         else if(pos[nums[i]].size() > 1) {
        //             res.push_back(pos[nums[i]][0]);
        //             res.push_back(pos[nums[i]][1]);
        //             break;
        //         }
        //     }
        // }
        // return res;
    }
};