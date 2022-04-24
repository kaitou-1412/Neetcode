class Solution {
public:
    vector<int> countBits(int n) {
        int count = 1;
        int limit;
        vector<int> res;
        res.push_back(0);
        while(count <= n) {
            limit = 1 << (int)(log2(count));
            res.push_back(res[count - limit]+1);
            count++;
        }
        return res;
    }
};