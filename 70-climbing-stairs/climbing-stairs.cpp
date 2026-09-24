class Solution {
public:
    int countSteps(int idx,int n,vector<int>& dp)
    {
        if(idx==n)
        {
            return 1;
        }
        if(idx==n-1)
        {
            return 1;
        }

        if(dp[idx]!=-1)return dp[idx];

        return dp[idx]=countSteps(idx+1,n,dp)+countSteps(idx+2,n,dp);

    }
    int climbStairs(int n) {
        int idx=0;
        vector<int> dp(n+1,-1);
        int ans=countSteps(idx,n,dp);
        return ans;
    }
};