//  Interleaving String

class Solution {
public:
    string right;
    string down;
    bool dfs(int i,int j,int k,string& s3,vector<vector<int> >& is_visited)
    {
        if(i<right.size() &&j<down.size())
        {
            if(is_visited[i][j])
                return false;
            else
                is_visited[i][j] = 1;
        }
        if(k==s3.size())
            return true;
        if(i<right.size() && right[i] == s3[k])
            if(dfs(i+1,j,k+1,s3,is_visited))
                return true;
        if(j<down.size()&&down[j] == s3[k])
            if(dfs(i,j+1,k+1,s3,is_visited))
                return true;
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        vector<vector<int> > is_visited(s1.size(),vector<int>(s2.size(),0));
        right = s1;
        down = s2;
        
        return dfs(0,0,0,s3,is_visited);
    }
};
