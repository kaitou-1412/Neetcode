class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        int mid, count, res = end;
        while(start<=end) {
            mid = start + (end - start)/2;
            count = 0;
            for(int i=0; i<piles.size(); i++) {
                count += piles[i]/mid;
                if(piles[i] % mid != 0) count++; 
            }
            if(count <= h) {
                res = min(res, mid);
                end = mid-1;
            } else start = mid+1;
        }
        return res;
    }
};