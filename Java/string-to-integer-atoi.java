//  String to Integer (atoi)

// Time O(N), Space O(1)
class Solution {
    public int myAtoi(String str) {
        long res = 0;
        int i = 0;
        for (; i < str.length() && str.charAt(i)==' '; i ++);
        if (i >= str.length())  return 0;
        char cur = str.charAt(i);
        if (!Character.isDigit(cur) && cur!='+' && cur!='-')    return 0;
        int flag = (cur=='-' ? -1 : 1);
        if (cur=='+' || cur=='-')   i ++;
        for (; i<str.length() && Character.isDigit(str.charAt(i)); i++) {
            res = res * 10 + (str.charAt(i) - '0');
            if (flag * res > Integer.MAX_VALUE) return Integer.MAX_VALUE;
            if (flag * res < Integer.MIN_VALUE) return Integer.MIN_VALUE;
        }
        return (int)(flag*res);
    }
}
