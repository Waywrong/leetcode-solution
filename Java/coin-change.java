//  Coin Change

// Time O(N), Space O(N)
class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] table = new int[amount+1];
        for (int i=0; i<=amount; i++)
            table[i] = amount+1;
        table[0] = 0;
        for (int i=1; i<=amount; i++) 
            for (int j=0; j<coins.length; j++)
                if (coins[j] <= i)
                    table[i] = Math.min(table[i], table[i-coins[j]]+1);
        return (table[amount]>amount) ? -1 : table[amount];
    }
}