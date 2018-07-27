//  Count and Say

// Time O(NK), Space O(1)
class Solution {
    public String countAndSay(int n) {
        String res = "1";
        for (int i=1; i<n; i++)
            res = generateNextString(res);
        return res;
    }
    
    private String generateNextString(String s) {
        StringBuffer temp = new StringBuffer();
        int i = 0;
        while (i < s.length()) {
            int count = 1;
            char ch = s.charAt(i);
            int j = i+1;
            while (j<s.length() && s.charAt(j)==ch) {
                count ++;
                j ++;
            }
            temp.append(count);
            temp.append(ch);
            i = j;
        }
        return temp.toString();
    }
}
