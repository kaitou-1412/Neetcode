class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroes = 0;
        for(auto num: nums) if(num == 0) zeroes++;
        vector<int> res;
        if(zeroes > 1) {
            for(int i=0; i<nums.size(); i++) res.push_back(0);
        } else if(zeroes == 1) {
            int prod = 1;
            for(int i=0; i<nums.size(); i++) {
                if(nums[i] != 0) prod *= nums[i];
            }
            for(int i=0; i<nums.size(); i++) {
                if(nums[i] == 0) res.push_back(prod);
                else res.push_back(0);
            }
        } else {
            int prod = 1;
            for(int i=0; i<nums.size(); i++) prod *= nums[i];
            for(int i=0; i<nums.size(); i++) res.push_back(prod/nums[i]);
        }
        return res;
    }
};