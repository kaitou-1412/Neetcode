class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int i=0; i<n; i++) sum += nums[i];
        if(sum%2!=0) return false;
        int subSetSum = sum / 2;
        vector<bool> dp(subSetSum + 1, false);
        dp[0] = true;
        for (int curr: nums) {
            for (int j = subSetSum; j >= curr; j--) {
                dp[j] = dp[j] || dp[j - curr];
            }
        }
        return dp[subSetSum];
    }
};