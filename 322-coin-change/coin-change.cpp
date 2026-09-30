class Solution {
public:
    int f(int ind,int amount ,vector<int>&coins,vector<vector<int>>&dp)
    {
        if(ind==0)
        {
            if(amount%coins[ind]==0)
            return amount/coins[ind];
            else return 1e8;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];

        int take=INT_MAX;
        if(coins[ind]<=amount)
        {
            take=1+f(ind,amount-coins[ind],coins,dp);
        }
        int nottake=f(ind-1,amount,coins,dp);

        return dp[ind][amount]=min(take,nottake);
        
    }
    int coinChange(vector<int>& coins, int amount) {

        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans=f(coins.size()-1,amount,coins,dp);
        if(ans>=1e8)
        return -1;
        else
        return ans;

        
    }
};