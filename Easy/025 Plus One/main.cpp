class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum, carry;
        for(int i = digits.size()-1; i>=0; i--) {
            if(i == digits.size()-1) digits[i] += 1;
            if(digits[i] >= 10) {
                sum = digits[i]%10;
                carry = digits[i]/10;
                digits[i] = sum;
                if(i!=0) digits[i-1] += carry;
                else {
                    digits.insert(digits.begin(), carry);
                    break;
                }
            } else break;
        }
        return digits;
    }
};