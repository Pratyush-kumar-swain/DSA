class Solution {
public:

    int recursion(int i,int j,vector<vector<int>>& dp)
    {
        if(i==0 && j==0)
        {
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int left=0,up=0;
        if(j!=0)
        left=recursion(i,j-1,dp);
        if(i!=0)
        up=recursion(i-1,j,dp);

        return dp[i][j]=left+up;
    }
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans=recursion(m-1,n-1,dp);
        return ans;
    }
};