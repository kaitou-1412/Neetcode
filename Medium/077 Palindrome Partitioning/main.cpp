class Solution {
public:
    bool isPalindrome(string &s, int low, int high) {
        while(low < high) {
            if(s[low++] != s[high--]) return false;
        }
        return true;
    }
    void dfs(vector<vector<string>> &res, string &s, int start, vector<string> &v) {
        if(start >= s.length()) res.push_back(v);
        for(int end = start; end<s.length(); end++) {
            if(isPalindrome(s, start, end)) {
                v.push_back(s.substr(start, end-start+1));
                dfs(res, s, end+1, v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> v;
        dfs(res, s, 0, v);
        return res;
    }
};