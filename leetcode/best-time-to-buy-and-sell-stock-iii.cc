//  Best Time to Buy and Sell Stock III

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)  return 0;
        int max_profit = INT_MIN;
        for (int i=0; i<prices.size(); i++) {
            int l_max_profit = maxProfit(prices, 0, i);
            int r_max_profit = maxProfit(prices, i+1, prices.size()-1);
            max_profit = max(max_profit, l_max_profit + r_max_profit);
        }
        return max_profit;
    }
    
    int maxProfit(vector<int> &prices, int l, int r) {
        if (l >= r) return 0;
        int min_price = prices[l], max_profit = 0;
        for (int i=l+1; i<=r; i++) {
            max_profit = max(max_profit, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }
        return max_profit;
    }
};