class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1) return 0;
        // vector<int> sold(n+1, 0);
        // vector<int> held(n+1, 0);
        // vector<int> reset(n+1, 0);
        // sold[0] = INT_MIN;
        // held[0] = INT_MIN;
        // reset[0] = 0;
        // for(int i=1; i<=n; i++) {
        //     sold[i] = held[i-1] + prices[i-1];
        //     held[i] = max(reset[i-1] - prices[i-1], held[i-1]);
        //     reset[i] = max(sold[i-1], reset[i-1]);
        // }
        // return max(sold[n], reset[n]);
        int sold = INT_MIN, held = INT_MIN, reset = 0, preSold;
        for(int price: prices) {
            preSold = sold;
            sold = held + price;
            held = max(held, reset - price);
            reset = max(reset, preSold);
        }
        return max(sold, reset);
    }
};