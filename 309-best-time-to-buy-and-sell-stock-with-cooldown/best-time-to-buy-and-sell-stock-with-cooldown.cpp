class Solution {
public:
    int f(int ind,int buy,int cooldown,vector<int>&prices,vector<vector<vector<int>>>&dp)
    {
        if(ind==prices.size())
        return 0;

        if(dp[ind][buy][cooldown]!=-1) return dp[ind][buy][cooldown];

        if(buy && !cooldown)
        {
            return dp[ind][buy][cooldown]=max(-prices[ind]+f(ind+1,0,0,prices,dp),f(ind+1,1,0,prices,dp));
        }
        else if(buy && cooldown)
        {
            return dp[ind][buy][cooldown]=f(ind+1,1,0,prices,dp);
        }
        else
        {
            return dp[ind][buy][cooldown]=max(prices[ind]+f(ind+1,1,1,prices,dp),f(ind+1,0,0,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,
           vector<vector<int>>(2,vector<int>(2,-1))

        );
        return f(0,1,0,prices,dp);
        
    }
};