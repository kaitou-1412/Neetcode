class Solution {
public:
    int expandAroundCenter(string s, int left, int right) {
        int l=left, r=right;
        while(0<=l && r<s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        int len = r-l-1;
        if(len <= 0) return 0;
        return (len+1)/2;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int start=0, end=0;
        int res = 0;
        for (int i=0; i<n; i++) {
            res += expandAroundCenter(s, i, i);
            res += expandAroundCenter(s, i, i+1);
        }
        return res;
    }
};