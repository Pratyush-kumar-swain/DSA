class Solution {
public:
    int longestPalindromeSubseq(string s) {

        
        int a=s.size();
        string r="";int i=a-1;
        while(i>=0)
        {
            r=r+s[i];
            i--;
        }
        // vector<vector<int>>dp(a,vector<int>(b,-1));
         //return f(a-1,b-1,text1,text2,dp); call for memoization....
   
   // TABULATION...
   vector<vector<int>>dp(a+1,vector<int>(a+1,0));
         for(int i=0;i<=a;i++) dp[i][0];
         for(int j=0;j<=a;j++) dp[0][j];

         for(int i=1;i<=a;i++)
         {
            for(int j=1;j<=a;j++)
            {
                if(s[i-1]==r[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
         }
        return dp[a][a];
        
    }
};