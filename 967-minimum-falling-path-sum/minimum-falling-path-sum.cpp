class Solution {
public:

    int recursion(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
         if(i<0 || j<0  || j>=matrix[0].size())
        return 1e9;

        if(i==0)
        return matrix[i][j];

       
        if(dp[i][j]!=INT_MAX) return dp[i][j];

        int up=INT_MAX,up_left=INT_MAX,up_right=INT_MAX;
        up=matrix[i][j]+recursion(i-1,j,matrix,dp);
        up_left=matrix[i][j]+recursion(i-1,j-1,matrix,dp);
        up_right=matrix[i][j]+recursion(i-1,j+1,matrix,dp);

        return dp[i][j]=min({up_left,up_right,up});

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int m=matrix.size();
        int n=matrix[0].size();

        int ans=INT_MAX;
         vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));
        for(int i=0;i<n;i++)
        {
            ans=min(recursion(m-1,i,matrix,dp),ans);
        }
        return ans;
    }
};