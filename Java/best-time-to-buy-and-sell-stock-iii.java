//  Best Time to Buy and Sell Stock III

// Time O(N^2), Space O(1)
class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length == 0)
            return 0;
        int max_profit = Integer.MIN_VALUE;
        int l_max_profit = 0, r_max_profit = 0;
        for (int i=0; i<prices.length; i++) {
            l_max_profit = maxProfit(prices, 0, i);
            r_max_profit = maxProfit(prices, i+1, prices.length-1);
            max_profit = Math.max(l_max_profit + r_max_profit, max_profit);
        }
        return max_profit;
    }
    
    private int maxProfit(int[] prices, int start, int end) {
        if (start >= end)
            return 0;
        int max_profit = 0, min_price = prices[start];
        for (int i=start+1; i<=end; i++) {
            max_profit = Math.max(prices[i] - min_price, max_profit);
            min_price = Math.min(prices[i], min_price);
        }
        return max_profit;
    }
}