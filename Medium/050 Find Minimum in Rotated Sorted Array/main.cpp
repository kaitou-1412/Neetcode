class Solution {
public:
    int findMin(vector<int>& nums) {
        int k = 0;
        int n = nums.size();
        int start = 0, end = n-1, mid;
        while(start<=end) {
            mid = start + (end - start)/2;
            if(mid<n-1 && nums[mid]>nums[mid+1]) {
                k = n-1-mid;
                break;
            } else if(0<mid && nums[mid-1]>nums[mid]) {
                k = n-mid;
                break;
            } else if(nums[mid] < nums[0]) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        k = n-k;
        return nums[k%n];
    }
};