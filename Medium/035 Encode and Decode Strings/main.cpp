class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        // write your code here
        if(strs.size() == 0) return "";
        string res = strs[0];
        for(int i=1; i<strs.size(); i++) res += ":;" + strs[i];
        return res;
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        // write your code here
        vector<string> res;
        int n = str.size();
        if(n == 0) return res;
        string curr = "";
        for(int i=0; i<n; i++) {
            if(i+1<n && str[i] == ":" && str[i+1] == ";") {
                res.push_back(curr);
                curr = "";
                i++;
            } else curr += str[i];
        }
        if(curr != "") {
            res.push_back(curr);
            curr = "";
        }
        return res;
    }
};