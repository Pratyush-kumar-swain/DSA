class Solution {
public:
    int maxRob1(int idx,vector<int>& nums,vector<int>& dp)
    {
        if(idx==nums.size()-2)
        return nums[nums.size()-2];
        if(idx>=nums.size()-1)
        return 0;
        if(dp[idx]!=-1) return dp[idx];
        int pick=maxRob1(idx+2,nums,dp)+nums[idx];
        int notpick=maxRob1(idx+1,nums,dp);
        return dp[idx]=max(pick,notpick);
    }
     int maxRob2(int idx,vector<int>& nums,vector<int>& dp2)
    {
        if(idx==nums.size()-1)
        return nums[nums.size()-1];
        if(idx>nums.size()-1)
        return 0;
        if(dp2[idx]!=-1) return dp2[idx];
        int pick=maxRob2(idx+2,nums,dp2)+nums[idx];
        int notpick=maxRob2(idx+1,nums,dp2);
        return dp2[idx]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {

        int n=nums.size();
        if(n==1)
        return nums[0];

        vector<int> dp(n+1,-1);
        int ans1=maxRob1(0,nums,dp);

        vector<int> dp2(n+1,-1);
        int ans2=maxRob2(1,nums,dp2);
       return max(ans1,ans2);
    }
};