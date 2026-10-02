class Solution {
public:
    int f(int ind,int buy,int cap,vector<int>&prices,vector<vector<vector<int>>>& dp)
    {
        if(cap==0) return 0;
        if(ind==prices.size()) return 0;

        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];

        int profit=0;
        if(buy)
        {
        return dp[ind][buy][cap]=max(-prices[ind]+f(ind+1,0,cap,prices,dp),f(ind+1,1,cap,prices,dp));
        }

        return dp[ind][buy][cap]=max(prices[ind]+f(ind+1,1,cap-1,prices,dp),f(ind+1,0,cap,prices,dp));

   

    }
    int maxProfit(vector<int>& prices) {
        int p=prices.size();
        vector<vector<vector<int>>> dp(p+1,
                                    vector<vector<int>>(2,vector<int>(3,-1)));

        for(int i=0;i<=p;i++)
        {
            for(int j=0;j<=1;j++)
            {
                dp[i][j][0]=0;
            }
        }
        for(int i=0;i<=1;i++)
        {
            for(int j=0;j<=2;j++)
            {
                dp[p][i][j]=0;
            }
        }
        for(int ind=p-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=2;cap++)
                {
                    if(buy)
                    {
                        dp[ind][buy][cap]=max(-prices[ind]+dp[ind+1][0][cap],dp[ind+1][1][cap]);
                    }
                    else
                    {
                        dp[ind][buy][cap]=max(prices[ind]+dp[ind+1][1][cap-1],dp[ind+1][0][cap]);
                    }
                }
            }
        }

       // return f(0,1,2,prices,dp);
     return dp[0][1][2];
    }
};