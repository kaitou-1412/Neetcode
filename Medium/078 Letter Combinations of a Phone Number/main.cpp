class Solution {
public:
    unordered_map<int, string> mp;
    void solve(vector<string> &res, string &s, string digits, int curr) {
        if(curr == digits.length()) {
            res.push_back(s);
            return;
        }
        int digit = digits[curr] - '0';
        for(char ch: mp[digit]) {
            s += ch;
            solve(res, s, digits, curr+1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        vector<string> res;
        string s = "";
        solve(res, s, digits, 0);
        return res;
    }
};