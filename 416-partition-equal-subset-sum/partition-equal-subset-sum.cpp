class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int target=0;
        for(int i=0;i<nums.size();i++)
        {
            target+=nums[i];
        }
        if(target%2==1)
        return false;
        else
        {
            target=target/2;
            vector<vector<bool>>dp(nums.size(),vector<bool>(target+1,false));
            for(int i=0;i<nums.size();i++)
            {
                dp[i][0]=true;
            }
          //  if(nums[0]==target)
          //  dp[0][nums[0]]=true;
            for(int ind=1;ind<nums.size();ind++)
            {
                for(int t=1;t<=target;t++)
                {
                    bool take=false;
                    if(t>=nums[ind])
                    take=dp[ind-1][t-nums[ind]];
                    bool nottake=dp[ind-1][t];
                    dp[ind][t]=take|nottake;
                }
            }
            return dp[nums.size()-1][target];
        }
        
    }
};