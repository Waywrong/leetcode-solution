//  Add Strings

// Time O(M+N), Space O(N)
class Solution {
    public String addStrings(String num1, String num2) {
        int p1 = num1.length()-1, p2 = num2.length()-1, k = 0;
        StringBuffer sb = new StringBuffer();
        while (p1>=0 || p2>=0) {
            int t = (p1>=0 ? num1.charAt(p1--)-'0' : 0) + (p2>=0 ? num2.charAt(p2--)-'0' : 0) + k;
            sb.append(t%10);
            k = t / 10;
        }
        if (k == 1)
            sb.append(1);
        return sb.reverse().toString();
    }
}