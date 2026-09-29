class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {

        int total=0;int n=stones.size();
        for(int i=0;i<stones.size();i++) total+=stones[i];
         
        vector<vector<bool>> dp(n,vector<bool>(total+1,0));
        
        for(int i=0;i<n;i++) dp[i][0]=true;
        if(stones[0]<=total) dp[0][total]=true;

        for(int i=1;i<n;i++)
        {
            for(int t=1;t<=total;t++)
            {
                bool take=false;
                if(stones[i]<=t)
                take=dp[i-1][t-stones[i]];
                bool nottake=dp[i-1][t];
                dp[i][t]=take||nottake;
            }
        }
        int ans=1e9;
        for(int i=0;i<=total;i++)
        {
            if(dp[n-1][i])
            {
                ans=min(ans,abs(i-(total-i)));
            }

        }
        return ans;
    }
};