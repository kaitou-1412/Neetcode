class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet;
        for(auto x: nums) numsSet.insert(x);
        int start = 0, count = 0, max_count = 0;
        for(auto x: numsSet) {
            if (numsSet.find(x-1)!=numsSet.end()) continue;
            else {
                start = x;
                count = 1;
                while (numsSet.find(++start)!=numsSet.end()) count++;
                max_count = max(max_count, count);
            }
        }
        return max_count;
    }
};