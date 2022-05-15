class Solution {
public:
    int rob_simple(vector<int>& nums, int start, int end) {
        int t1 = 0;
        int t2 = 0;

        for (int i = start; i <= end; i++) {
            int temp = t1;
            int current = nums[i];
            t1 = max(current + t2, t1);
            t2 = temp;
        }

        return t1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        
        int max1 = rob_simple(nums, 0, n-2);
        int max2 = rob_simple(nums, 1, n-1);

        return max(max1, max2);
    }
};