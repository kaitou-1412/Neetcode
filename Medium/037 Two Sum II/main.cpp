class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int start = 0, end = n-1, currSum;
        while(start<end) {
            currSum = numbers[start] + numbers[end];
            if(currSum == target) {
                return {start+1, end+1};
            } else if(currSum < target) {
                start++;
            } else {
                end--;
            }
        }
        return {0, 0};
    }
};