class Solution {
public:
    int minPath(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(i==0 && j==0)
        return grid[i][j];

        if(dp[i][j]!=-1) return dp[i][j];

        int right=INT_MAX,up=INT_MAX;
        if(i!=0)
        up=grid[i][j]+minPath(i-1,j,grid,dp);
        if(j!=0)
        right=grid[i][j]+minPath(i,j-1,grid,dp);
        
        return dp[i][j]=min(up,right);

    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=minPath(n-1,m-1,grid,dp);

        return ans;
    }
};