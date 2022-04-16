class Solution {
public:
    bool isPalindrome(string s) {
        string s2 = "";
        for(int i=0; i<s.size(); i++) {
            if(('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z') || ('0' <= s[i] && s[i] <= '9')) {
                if('A' <= s[i] && s[i] <= 'Z') s[i] += 32;
                s2 += s[i];
            }
        }
        int n = s2.size();
        for(int i=0; i<n/2; i++) {
            if(s2[i] != s2[n-i-1]) return false;
        }
        return true;
    }
};