class Solution {
public:
    void result(vector<string>& res, int n, string s) {
        int a = 0;
        for(int i=0; i<s.size(); i++) if(s[i] == '(') a++;
        int b = s.size() - a;
        if(a < b || n < a) return;
        if(a == b && b == n) {
            res.push_back(s);
            return;
        }
        result(res, n, s + "("); 
        result(res, n, s + ")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        result(res, n, "");
        return res;
    }
};