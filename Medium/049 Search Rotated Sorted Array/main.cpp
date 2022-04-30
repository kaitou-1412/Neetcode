class Solution {
public:
    int search(vector<int>& nums, int target) {
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
        if(k == 0) {
            start = 0; 
            end = n-1;
            while(start<=end) {
                mid = start + (end-start)/2;
                if(nums[mid] == target) {
                    return mid;
                } else if(nums[mid] < target) {
                    start = mid+1;
                } else {
                    end = mid-1;
                }
            }
        } else {
            start = 0; 
            end = n-1-k;
            while(start <= end) {
                mid = start + (end-start)/2;
                if(nums[mid] == target) {
                    return mid;
                } else if(nums[mid] < target) {
                    start = mid+1;
                } else {
                    end = mid-1;
                }
            }
            start = n-k; 
            end = n-1;
            while(start <= end) {
                mid = start + (end-start)/2;
                if(nums[mid] == target) {
                    return mid;
                } else if(nums[mid] < target) {
                    start = mid+1;
                } else {
                    end = mid-1;
                }
            }
        }
        return -1;
    }
};