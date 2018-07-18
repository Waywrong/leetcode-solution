//  Best Time to Buy and Sell Stock

// Time O(N), Space O(1)
class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length < 2)
            return 0;
        int max_profit = 0, min_price = prices[0];
        for (int i=1; i<prices.length; i++) {
            max_profit = Math.max(max_profit, prices[i] - min_price);
            min_price = Math.min(min_price, prices[i]);
        }
        return max_profit;
    }
}