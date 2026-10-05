class Solution {
public:
    int smallestNumber(int n) {
        long x=(1<<9);
        while(x>1)
        {
            if((x&n)!=0)
            break;
            x=x>>1;
        }
        x=x<<1;
        return x-1 ;
    }
};