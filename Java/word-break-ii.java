//  Word Break II

// Time O(N^2), Space O(N^2)
class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        int size = s.length();
        boolean[] f = new boolean[size+1];
        f[0] = true;
        boolean[][] words = new boolean[size][size];
        for (int i=1; i<=size; i++) {
            for (int j=0; j<i; j++) {
                if (f[j] && wordDict.contains(s.substring(j, i))) {
                    f[i] = true;
                    words[j][i-1] = true;
                }
            }
        }
        List<String> res = new ArrayList<String>();
        List<String> path = new ArrayList<String>();
        dfs(s, words, 0, path, res);
        return res;
    }
    
    private void dfs(String s, boolean[][] words, int cur, List<String> path, List<String> res) {
        if (cur == s.length()) {
            String temp = "";
            List<Integer> l = new ArrayList(path);
            for (int i=0; i<l.size(); i++) 
                temp = temp + l.get(i) + " ";
            res.add(temp);
        }
        for (int i=0; i<s.length(); i++) {
            if (words[cur][i]) {
                path.add(s.substring(cur, i+1));
                dfs(s, words, i+1, path, res);
                path.remove(path.size()-1);
            }
        }
    }
}