class Solution {
public:
    bool isPowerOfTwo(int n) {

        int a=__builtin_popcount(n);
        if(a==1 && n>0)
        return true ;
        return false;

        
    }
};