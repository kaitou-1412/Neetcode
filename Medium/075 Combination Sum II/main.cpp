class Solution {
public:
   void subset_sum(vector<int>& arr, vector<vector<int>>& ans, vector<int>& v, int i, int sum) {
        if(i >= arr.size() || sum <= 0) {
            if(sum == 0) ans.push_back(v);
            return;
        }

        // pick it
        v.push_back(arr[i]);
        subset_sum(arr, ans, v, i+1, sum-arr[i]);
        v.pop_back();

        // ignore duplicate elements...
        while(i+1 < arr.size() && arr[i] == arr[i+1]) i++;

        // don't pick it
        subset_sum(arr, ans, v, i+1, sum);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        subset_sum(candidates, ans, v, 0, target);
        return ans;
    }
};