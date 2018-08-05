//  Best Time to Buy and Sell Stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)  return 0;
        int max_profit = 0, min_price = prices[0];
        int buy_day = 0, sell_day = -1, pre_buy_day = 0;
        for (int i=1; i<prices.size(); i++) {
            if (prices[i] - min_price > max_profit) {
                max_profit = prices[i] - min_price;
                sell_day = i;
            }
            if (prices[i] < min_price) {
                pre_buy_day = i;
                min_price = prices[i];
            }
        }
        cout << pre_buy_day << "\t" << sell_day << endl;
        return max_profit;
    }
};