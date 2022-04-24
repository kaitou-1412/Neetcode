class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for(int i=1; i<=nums.size(); i++) res = res xor i;
        for(int i=0; i<nums.size(); i++) res = res xor nums[i];
        return res;
    }
};