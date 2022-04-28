class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 1, n = s.size();
        if(n<=1) return n;
        unordered_map<char, int> mp;
        mp[s[l]]++;
        int res = 1;
        while(r!=n) {
            mp[s[r]]++;
            while(mp[s[r]] > 1 && l<r) {
                mp[s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};