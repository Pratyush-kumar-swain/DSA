class Solution {
public:
    int minPathSum(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>>& dp)
    {
        if(i==n)
        return triangle[i][j];

        if(i>=n)
        return 0;

        if(dp[i][j]!=INT_MIN) return dp[i][j];

        int down=INT_MIN,diagonal=INT_MIN;

        down=triangle[i][j]+minPathSum(i+1,j,n,triangle,dp);
        diagonal=triangle[i][j]+minPathSum(i+1,j+1,n,triangle,dp);

        return dp[i][j]=min(down,diagonal);
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {

        int n=triangle.size()-1;
        int maxi=0;
        for(int i=0;i<=n;i++)
        {
            maxi=max(maxi,(int)triangle[i].size());
        }
        vector<vector<int>> dp(n+1,vector<int>(maxi,INT_MIN));
        int ans=minPathSum(0,0,n,triangle,dp);
        
        return ans;
    }
};