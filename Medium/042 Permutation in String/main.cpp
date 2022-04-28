class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        string a = s1, b = "";
        int m = s1.size(), n = s2.size();
        sort(a.begin(), a.end());
        for(int i=0; i<=n-m; i++) {
            b = s2.substr(i, m);
            sort(b.begin(), b.end());
            if(a == b) return true;
        }
        return false;
    }
};