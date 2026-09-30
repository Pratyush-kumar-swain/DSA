class Solution {
public:
    int f(int ind,int target,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(ind==0)
        {
            if(target==0 && nums[ind]==0) return 2;

            if(target==0||nums[ind]==target)
            return 1;

            return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
       
         int take=0;
         if(nums[ind]<=target)
         take=f(ind-1,target-nums[ind],nums,dp);
        int nottake=f(ind-1,target,nums,dp);

        return dp[ind][target]=take+nottake;
    }
    int findTargetSumWays(vector<int>& nums, int target) { 

        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++) total+=nums[i];
  
        if(total-abs(target)<0||(total-target)%2!=0) return false;
        int newtarget=(total-target)/2;
        vector<vector<int>>dp(n,vector<int>(newtarget+1,-1));


        int ans=f(n-1,newtarget,nums,dp);

        return ans;
        
    }
};