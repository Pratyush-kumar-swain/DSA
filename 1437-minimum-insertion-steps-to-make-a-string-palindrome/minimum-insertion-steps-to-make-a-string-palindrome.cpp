class Solution {
public:
    int LCS(int ind1,int ind2,string& s1,string& s2,vector<vector<int>>& dp)
    {
        if(ind1==s1.size() || ind2==s2.size())
        return 0;

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

        if(s1[ind1]==s2[ind2])
        dp[ind1][ind2]=1+LCS(ind1+1,ind2+1,s1,s2,dp);
        else
        dp[ind1][ind2]=max(LCS(ind1+1,ind2,s1,s2,dp),LCS(ind1,ind2+1,s1,s2,dp));

        return dp[ind1][ind2];
    }
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        string k=s;
        reverse(k.begin(),k.end());
        return n-LCS(0,0,s,k,dp);
        
    }
};