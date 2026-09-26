class Solution {
public:
    int uniquePath(int i,int j,vector<vector<int>>& Grid,vector<vector<int>>& dp)
    {
        if(i==0 && j==0)
        return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        int right=0,up=0;
        if(j!=0 && Grid[i][j-1]==0)
        right=uniquePath(i,j-1,Grid,dp);

        if(i!=0 && Grid[i-1][j]==0)
        up=uniquePath(i-1,j,Grid,dp);

        return dp[i][j]=right+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        if(obstacleGrid[m-1][n-1]==1)
        return 0; 

        vector<vector<int>> dp(m,vector<int> (n,-1));

        int ans=uniquePath(m-1,n-1,obstacleGrid,dp);
        return ans;
        
    }
};