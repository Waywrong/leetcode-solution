//  Valid Palindrome

// Time O(N), Space O(1)
class Solution {
    public boolean isPalindrome(String s) {
        if (s.length() == 0)    return true;
        int l = 0, r = s.length()-1;
        while (l <= r) {
            char a = s.charAt(l);
            char b = s.charAt(r);
            if (!Character.isLetterOrDigit(a)) {
                l ++;
                continue;
            }
            if (!Character.isLetterOrDigit(b)) {
                r --;
                continue;
            }
            if (Character.toLowerCase(a) != Character.toLowerCase(b))
                return false;
            l ++; r --;
        }
        return true;
    }
}
