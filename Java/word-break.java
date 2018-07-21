//  Word Break

// Time O(N^2), Space O(N)
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        int size = s.length();
        boolean[] words = new boolean[size+1];
        words[0] = true;
        for (int i=1; i<=size; i++) {
            for (int j=0; j<i; j++) {
                if (words[j] && wordDict.contains(s.substring(j, i))) {
                    words[i] = true;
                    break;
                }
            }
        }
        return words[size];
    }
}