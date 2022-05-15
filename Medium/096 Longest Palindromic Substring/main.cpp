class Solution {
public:
    int expandAroundCenter(string s, int left, int right) {
        int l=left, r=right;
        while(0<=l && r<s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int start=0, end=0;
        for (int i=0; i<n; i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);
            if (len > end - start) {
                start = i - (len-1)/2;
                end = i + len/2;
            }
        }
        return s.substr(start, end + 1 - start);
    }
};