class Solution {
public:
    vector<vector<int> > ans;
    void subsetsHelper(vector<int> nums, int indx, vector<int> arr)
    {
        if(indx==nums.size())
        {
            ans.push_back(arr);
            return;
        }
        
        //include the current element at index indx
        arr.push_back(nums[indx]);
        subsetsHelper(nums,indx+1,arr);
        arr.pop_back();
        
        //exclude the current element at index indx
        subsetsHelper(nums,indx+1,arr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        if(nums.size()==1)
        {
            return {{}, {nums[0]}};
        }
        subsetsHelper(nums,0,{});
        return ans;
        
    }

};