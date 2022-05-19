class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int i : nums) sum += i;      
        if (S > sum || S < -sum) return 0;  
        int dp[nums.size()][sum*2+1];
        memset(dp, 0, nums.size()*(sum*2+1)*sizeof(int));
        dp[0][nums[0]+sum] = 1;
        dp[0][-nums[0]+sum] += 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j <= 2*sum; j++) {
                if (dp[i-1][j] != 0) {
                    dp[i][j+nums[i]] += dp[i-1][j];
                    dp[i][j-nums[i]] += dp[i-1][j];
                }
            }
        }
        return dp[nums.size()-1][S+sum];
    }
};