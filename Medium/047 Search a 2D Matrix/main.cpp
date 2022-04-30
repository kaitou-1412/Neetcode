class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int start = 0, end = n-1, mid, m = matrix[0].size();
        if(n>1) {
            while(start<end) {
                mid = start + (end - start)/2;
                if(matrix[mid][0] == target) return true;
                else if(matrix[mid][0] < target && target <= matrix[mid][m-1]) {
                    start = mid;
                    break;
                } 
                else if(matrix[mid][m-1] < target) start = mid+1;
                else end = mid-1;
            }
        }
        int row = start;
        start = 0;
        end = m-1;
        while(start<=end) {
            mid = start + (end - start)/2;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] < target) start = mid+1;
            else end = mid-1;
        }
        return false;
    }
};