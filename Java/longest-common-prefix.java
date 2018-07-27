//  Longest Common Prefix

// Time O(NK), Space O(1)
class Solution {
    public String longestCommonPrefix(String[] strs) {
        StringBuffer res = new StringBuffer();
        int size = strs.length;
        if (size <= 0)  return "";
        if (size == 1)  return strs[0];
        int index = 0;
        while (true) {
            if (index >= strs[0].length())
                return res.toString();
            char cur = strs[0].charAt(index);
            for (int k = 1; k < size; k ++) 
                if (index >= strs[k].length() || strs[k].charAt(index) != cur)
                    return res.toString();
            res.append(cur);
            index ++;
        }
    }
}
