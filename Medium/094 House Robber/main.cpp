class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> maxAmount(n+1, 0);
        maxAmount[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--)
            maxAmount[i] = max(maxAmount[i+1], maxAmount[i+2] + nums[i]);
        return maxAmount[0];
    }
};