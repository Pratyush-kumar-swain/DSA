class Solution {
public:
    int hammingWeight(int n) {
        int x=n;
        int c=0;
        while(x!=1)
        {
            if((x&1)!=0) c++;
            x=x>>1;
        }
        return c+1;
    }
};