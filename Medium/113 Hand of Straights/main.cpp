class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0) return false;
        sort(hand.begin(), hand.end());
        unordered_map<int, int> mp;
        int sz = 0;
        for(int i=0; i<n; i++) mp[hand[i]]++;
        for(int num: hand) {
            if(mp[num]) {
                int m = num;
                int j = groupSize;
                while(j!=0) {
                    if(mp[m]) mp[m]--;
                    else return false;
                    m++;
                    j--;
                }
            }
        }
        return true;
    }
};