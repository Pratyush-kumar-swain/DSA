class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int x=(a|b);
        x=x^c;
        int i=1,ans=0;
      while(i<=x)
      {
        if((i&x)!=0)
        {
            if((i&c)!=0)
            ans+=1;
            else
            {
                if((a&i)!=0 && (b&i)!=0)
                ans+=2;
                else
                ans+=1;
            }
            
        }
        i=i<<1;
      }
      return ans;
    }
};