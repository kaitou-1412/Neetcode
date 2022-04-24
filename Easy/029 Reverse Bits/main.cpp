class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int index = 31;
        while(n!=0) {
            res += (n&1)*(1<<index);
            n = n>>1;
            index--;
        }
        return res;
    }
};