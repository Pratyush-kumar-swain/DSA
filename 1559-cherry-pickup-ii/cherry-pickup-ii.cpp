class Solution {
public:
    int f(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp)
    {
        
        if(j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size())
        return -1e8;

        if(i==grid.size()-1)
        {
            if(j1==j2)
            return grid[i][j1];
            else
            return grid[i][j1]+grid[i][j2];
        }
         int maxi=-1;
         if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

         for(int r1=-1;r1<2;r1++)
         {
            for(int r2=-1;r2<2;r2++)
            {
                if(j1==j2)
                {
                     maxi=max(grid[i][j1]+f(i+1,j1+r1,j2+r2,grid,dp),maxi);
                }
                else
                {
                     maxi=max(grid[i][j1]+grid[i][j2]+f(i+1,j1+r1,j2+r2,grid,dp),maxi);
                }
            }
         }
         return dp[i][j1][j2]=maxi;

    }
    int cherryPickup(vector<vector<int>>& grid) {

        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));

        return f(0,0,grid[0].size()-1,grid,dp);
        
    }
};